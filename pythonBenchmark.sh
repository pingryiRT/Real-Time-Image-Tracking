#!/bin/bash

cd src;
i=0
for i in {1..60}
do
        (time python benchmark.py) 2>&1 > /dev/null | grep real >> "../benchmark data/python.txt"
  
done   
