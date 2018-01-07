#!/bin/bash
mkdir -p build
cd build
mkdir -p dot
mkdir -p png
midfix=`date +%Y%m%d%H%M`
mkdir $midfix
cd $midfix
for i in `seq $2`
do
    ocaml ../rand.ml $1 > "./dot/graph"$i."dot"
    dot -Tpng "./dot/graph"$i."dot" -o "./png/graph"$i."png"
done


