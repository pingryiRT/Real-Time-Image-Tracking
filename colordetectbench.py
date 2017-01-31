# import the necessary packages
import numpy as np
import argparse
import cv2


#  parse the args
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", help = "path to the image")
args = vars(ap.parse_args())

# load the image
image = cv2.imread(args["image"]) #process

lower = np.array([0, 28, 29])
upper = np.array([178, 200, 181]) #obtained from range detector 
mask = cv2.inRange(image, lower, upper)
output = cv2.bitwise_and(image, image, mask = mask)

# show the images -- not necessary (just shows pic in terminal)
#cv2.imshow("images", np.hstack([image, output]))
#cv2.waitKey(0)