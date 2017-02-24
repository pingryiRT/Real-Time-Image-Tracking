#!/bin/bash
cd src;
i=0
for i in {1..60}
do
        (time java -cp /home/ubuntu/OpenCV/build/bin/opencv-320.jar:. "Benchmark") 2>&1 > /dev/null | grep real >> "../benchmark data/java.txt" 
done   
