# -*- coding: utf-8 -*-
"""
Created on Thu May  3 15:33:03 2018

@author: ECHOES
"""

from skimage import io
import numpy

#1 load the centroid

#1.1 get centroid
centroid = numpy.load('centroid.npy')

#1.2 get count
length = len(centroid)
print('length', length)

#2 load in original RGB pic
verify = io.imread('test1.jpg')
height, width, dim = verify.shape

#3 place the dots on the pic

i = 0
side = 5
while i < length:
    
    #round the coordinate
    x = int(round(centroid[i][0]))
    y = int(round(centroid[i][1]))
    
    """
    #place Green dots, channel: R, G, B -> 0, 1, 2
    m = 0
    while x + m < height and m < side:
        n = 0
        while y + n < width and n < side:
            verify[x + m, y + n] = [0, 255, 0]
            #including verify[x, y] = [0, 255, 0] and segmentation avoided
            n += 1
        m += 1
    """
    
    verify[x, y] = [0, 255, 0]
    if x + 1 < height:
        verify[x + 1, y] = [0, 255, 0]
    if y + 1 < width:
        verify[x, y + 1] = [0, 255, 0]
    if x - 1 >= 0:
        verify[x - 1, y] = [0, 255, 0]
    if y - 1 >= 0:
        verify[x, y - 1] = [0, 255, 0]
        
    i += 1

io.imshow(verify)
io.imsave('test1_verify1.jpg', verify)


