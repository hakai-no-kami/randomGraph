#!/bin/bash
rm build
mkdir build
cd build
mkdir dot
mkdir png
for i in `seq $1`
do
    echo $i
    ocaml ../rand.ml > "./dot/graph"$i."dot"
    dot -Tpng "./dot/graph"$i."dot" -o "./png/graph"$i."png"
done


