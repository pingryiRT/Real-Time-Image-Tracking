# import the necessary packages
import numpy as np
import cv2

def threshold(color, color2, t):
	return (abs(color[0]-color2[0]) < t) and (abs(color[1]-color2[1]) < t) and (abs(color[2]-color2[2]) < t)
color = [255,255,0] #cyan

image = cv2.imread("benchmark.jpg") #read in
x = 0
y = 0
count = 0
for i in range(0,len(image)): #rows
	for j in range(0,len(image[i])): #cols
		if threshold(color,image[i,j]):
			x += j
			y += i
			count += 1
if count == 0:
	print ("(0,0)")
else:
	print ("(%d, %d)" % (x/count, y/count))
			