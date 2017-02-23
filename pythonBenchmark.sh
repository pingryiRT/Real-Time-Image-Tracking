#!/bin/bash
i=0
for i in {1..20}
do
        (time python benchmark.py) 2>&1 > /dev/null | grep real >> "benchmark data/python.txt"
  
done   
