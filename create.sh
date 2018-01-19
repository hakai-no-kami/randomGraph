#!/bin/bash
mkdir -p build
cd build
midfix=`date +%Y%m%d%H%M`
mkdir $midfix
cd $midfix
for i in `seq $2`
do
    mkdir $i
    cd $i
    ocaml ../../../rand.ml $1
    dot -Tpng "graph.dot" -o "graph.png"
    dot -Tpng "graph2.dot" -o "graph2.png"
    mkdir "src"
    mv *.cpp "./src/"
    cd ..
done


