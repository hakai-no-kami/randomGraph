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
      (let r = (Random.int (min 6 ((List.length l)-1))) + 1 in 
        create_graph_sub ls ((x,pickup_node ls r)::g))
  in 
  let gt = create_graph_sub nodel [] in
  cut_graph gt []
let rec print_graph x y =
  Printf.printf "\tnode%d -> node%d\n" x y;()
let () =
  let arg = int_of_string(Sys.argv.(1)) in
  let graph_list = create_graph arg in
  let rec main_sub l =
    match l with
    | [] -> Printf.printf "}\n";()
    | (x,[]) :: xs -> Printf.printf "\tnode%d\n" x; main_sub xs;
    | (x,ls) :: xs -> List.iter (fun y -> print_graph x y) ls ; main_sub xs;
  in Printf.printf "digraph g{\n";main_sub graph_list