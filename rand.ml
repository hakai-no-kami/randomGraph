Random.self_init()
let node_list totalnum =
  (* let node_str = "node" in *)
  let rec nodelist_sub tn l = 
    if tn = 0 then
      l
    else
      (* nodelist_sub (tn-1) ((node_str^(string_of_int tn))::l) *)
      nodelist_sub (tn-1) (tn::l)
  in nodelist_sub totalnum []
let pickup_node nodel num =
  let rec pickup_node_sub l n =
    if n = 0 then
      l
    else
      let picked_node = List.nth nodel (Random.int (List.length nodel)) in
      if List.mem picked_node l then
        pickup_node_sub l n
      else
        pickup_node_sub (picked_node::l) (n-1)
  in pickup_node_sub [] num
let rec pick_list l num newl=
  if num = 0 then
    newl
  else
    match l with
    | [] -> newl
    | x :: xs -> pick_list xs (num-1) (x::newl)
let rec cut_graph g new_g =
  match g with
  | [] -> new_g
  | (x,[]) :: xs -> cut_graph xs ((x,[]) :: new_g)
  | (x,ls) :: xs -> (
    let ls_sort = List.sort compare ls in
    let len = List.length ls in
    let new_l = pick_list ls_sort ((len+1)/2) [] in
    cut_graph xs ((x,new_l):: new_g ))
let create_graph node_num =
  let nodel = node_list node_num in
  let rec create_graph_sub l g=
    match l with
    | [] -> g
    | x :: [] -> ((x,[])::g)
    | x :: ls -> 
      (let r = (Random.int (min 4 ((List.length l)-1))) + 1 in 
        create_graph_sub ls ((x,pickup_node ls r)::g))
  in 
  let gt = create_graph_sub nodel [] in
  cut_graph gt []
let rec search_prev g num meml=
  match g with
  | [] -> meml
  | (i,l) :: gs -> 
  (
    if List.mem num l then
      search_prev gs num (i::meml)
    else
      search_prev gs num meml
  )
let rec print_graph x y oc=
  Printf.fprintf oc "\tnode%d -> node%d\n" x y;()
let rec graph_io prev_g rest_g new_g =
  match rest_g with
  | [] -> new_g
  | (i,l) :: xs -> 
  (
    let meml = search_prev prev_g i [] in
    graph_io ((i,l)::prev_g) xs ((i,l,meml)::new_g)
  )
let creating_dot g=
  let file = "graph.dot" in
  let oc = open_out file in
  let rec creating_dot_sub l =
    match l with
    | [] -> Printf.fprintf oc "}\n";()
    | (x,[]) :: xs -> Printf.fprintf oc "\tnode%d\n" x; creating_dot_sub xs;
    | (x,ls) :: xs -> List.iter (fun y -> print_graph x y oc) ls ; creating_dot_sub xs;
  in Printf.fprintf oc "digraph g{\n"; creating_dot_sub g ;close_out oc
let print1 x y oc=
  Printf.fprintf oc "\tros::Publisher pub_%d_%d = n.advertise<std_msgs::String>(\"topic_%d_%d\", 1);\n" x y x y;()
let print2 x y oc = 
  Printf.fprintf oc "\t\tpub_%d_%d.publish(msg);\n" x y;()
let creating_pub_cpp i pub_list oc=
  Printf.fprintf oc "
  #include \"ros/ros.h\"
  #include \"std_msgs/String.h\"
  #include <sstream>
  int main(int argc, char **argv){
  \tros::init(argc, argv, \"node%d\");
  \tros::NodeHandle n;\n" i;
  List.iter (fun y -> print1 i y oc) pub_list ;
  Printf.fprintf oc 
  "\tros::Rate loop_rate(0.1);
  \tint count = 0;
  \twhile (ros::ok()){
  \t\tstd_msgs::String msg;
  \t\tstd::stringstream ss;
  \t\tss << \"hello world from node%d sending\" << count;
  \t\tmsg.data = ss.str();
  \t\tROS_INFO(\"%%s\", msg.data.c_str());\n" i;
  List.iter (fun y -> print2 i y oc) pub_list;
  Printf.fprintf oc "\t\tros::spinOnce();
  \t\tloop_rate.sleep();
  \t\t++count;
  \t}
  \treturn 0;
  }\n"
let print3 x y oc=
  Printf.fprintf oc 
  "void chatterCallback%d(const std_msgs::String::ConstPtr& msg){
  \tusleep(d(gen)*1000000);
  \tROS_INFO(\"I'm node%d and heard from node%d: [%%s]\", msg->data.c_str());
  }\n" x y x;()
let print4 x y oc = 
  Printf.fprintf oc "\tros::Subscriber sub_%d_%d = n.subscribe(\"topic_%d_%d\", 1, chatterCallback%d);\n" x y x y x;()
let creating_sub_cpp i sub_list oc=
  Printf.fprintf oc 
  "#include \"ros/ros.h\"
  #include \"std_msgs/String.h\"
  #include \"unistd.h\"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(2.0, 0.3);\n";
  List.iter (fun y -> print3 y i oc) sub_list;
  Printf.fprintf oc "int main(int argc, char **argv){
  \tros::init(argc, argv, \"node%d\");
  \tros::NodeHandle n;\n" i;
  List.iter (fun y -> print4 y i oc) sub_list;
  Printf.fprintf oc "
  \tros::spin();
  \treturn 0;
  }\n"
let print5 x y oc = 
  Printf.fprintf oc "\t\t\tsub_%d_%d_flag = 0;
  \t\t\tsub_%d_%d = n.subscribe(\"topic_%d_%d\", 1, &Node%d::middlemanCallback%d,this);\n" x y x y x y y x;()
let print6 x y oc=
  Printf.fprintf oc "\t\t\tpub_%d_%d = n.advertise<std_msgs::String>(\"topic_%d_%d\", 1);\n" x y x y;()
let print7 x y oc=
  Printf.fprintf oc "\t\tros::Publisher pub_%d_%d;\n" x y;()
let print8 x y oc = 
  Printf.fprintf oc 
  "\t\tint sub_%d_%d_flag;
  \t\tros::Subscriber sub_%d_%d;\n" x y x y;()
let print9 x y oc=
  Printf.fprintf oc "\t\t\t\tsub_%d_%d_flag = 0;\n" x y;()
let print10 x y oc=
  Printf.fprintf oc "sub_%d_%d_flag == 1 && " x y;()
let print11 x y oc=
  Printf.fprintf oc "\t\t\t\tpub_%d_%d.publish(msg);\n" x y;()
let print12 x y sub_list_ex pub_list oc = 
  Printf.fprintf oc "\t\tvoid middlemanCallback%d(const std_msgs::String::ConstPtr& msg){
  \t\t\tif(" x;
  List.iter (fun z -> print10 z y oc) sub_list_ex;
  Printf.fprintf oc " true){
  \t\t\t\tusleep(d(gen)*1000000);
  \t\t\t\tROS_INFO(\"I'm node%d last from node%d, intercepted: [%%s]\", msg->data.c_str());\n" y x;
  List.iter (fun z -> print11 y z oc) pub_list;
  List.iter (fun z -> print9 z y oc) sub_list_ex;
  Printf.fprintf oc "\t\t\t}
  \t\t\telse{
  \t\t\t\tROS_INFO(\"I'm node%d, from node%d intercepted: [%%s]\", msg->data.c_str());
  \t\t\t\tsub_%d_%d_flag = 1;
  \t\t\t}
  \t\t}\n" y x x y
let creating_sub_pub_cpp i sub_list pub_list oc=
  Printf.fprintf oc "
  #include \"ros/ros.h\"
  #include \"std_msgs/String.h\"
  #include \"unistd.h\"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(2.0, 0.3);
  class Node%d{
  \tpublic:
  \t\tNode%d(){\n" i i;
  List.iter (fun y -> print5 y i oc) sub_list;
  List.iter (fun y -> print6 i y oc) pub_list;
  Printf.fprintf oc "\t\t}\n";
  List.iter (fun y -> print12 y i (List.filter (fun x -> x !=y) sub_list) pub_list oc) sub_list;
  Printf.fprintf oc "\tprivate:
  \t\tros::NodeHandle n; \n";
  List.iter (fun y -> print7 i y oc) pub_list;
  List.iter (fun y -> print8 y i oc) sub_list;
  Printf.fprintf oc "};
  int main(int argc, char **argv){
  \tros::init(argc, argv, \"node%d\");
  \tNode%d node%d;
  \tros::spin();
  \treturn 0;
  }\n" i i i

let creating_node_cpp (i,pub_list,sub_list)=
  let file = "node"^(string_of_int i)^".cpp" in
  let oc = open_out file in
  (if sub_list = [] then
    creating_pub_cpp i pub_list oc
  else if pub_list = [] then
    creating_sub_cpp i sub_list oc
  else
    creating_sub_pub_cpp i sub_list pub_list oc);close_out oc
let rec creating_makefile_sub i oc=
  if(i != 0) then
      (Printf.fprintf oc 
"add_executable(node%d src/node%d.cpp)
target_link_libraries(node%d ${catkin_LIBRARIES})
add_dependencies(node%d test_src_generate_messages_cpp)\n" i i i i;creating_makefile_sub (i-1) oc)
  else ()
let creating_makefile i = 
  let file = "CMakeLists.txt" in
  let oc = open_out file in
  Printf.fprintf oc 
"cmake_minimum_required(VERSION 2.8.3)
project(test_src)
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
add_definitions(-std=c++11)
generate_messages(DEPENDENCIES std_msgs)
catkin_package()
include_directories(include ${catkin_INCLUDE_DIRS})\n";
creating_makefile_sub i oc;close_out oc

let () =
  let arg = int_of_string(Sys.argv.(1)) in
  let graph_list = create_graph arg in
  let graph_sub_pub = graph_io [] graph_list [] in
  creating_dot graph_list;List.iter creating_node_cpp graph_sub_pub;creating_makefile arg;()