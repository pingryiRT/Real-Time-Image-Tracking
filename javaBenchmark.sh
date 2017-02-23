#!/bin/bash
i=0
for i in {1..20}
do
        (time java ./src/benchmark) 2>&1 > /dev/null | grep real >> "benchmark data/java.txt"  
done   
