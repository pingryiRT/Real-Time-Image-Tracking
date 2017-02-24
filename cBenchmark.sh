#!/bin/bash

cd src;
i=0
for i in {1..60}
do
         (time ./benchmark) 2>&1 > /dev/null | grep real >> "../benchmark data/c.txt"  
done   
