#!/bin/bash

for ((i=5;i<=30;i+=1));
do
    ./$1 $i >> ./$1.dat
done
