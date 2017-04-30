#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec  1 20:54:32 2016

@author: WayNoxchi
"""
import numpy as np

Wt0 = [1,2,0]
Wt1 = [0,0,0]

#def vecCopy(vector):
#    newvec = []
#    for i in range(len(vector)):
#        newvec.append(vector[i])
#    return newvec
#
#Wt1 = vecCopy(Wt0)
#Wt0 *= 2
#
#Wt = 0
#Wt1 = 33
#Wt = Wt1
#Wt1 += 999
#print('Wt: {}  Wt1:{}'.format(Wt, Wt1))

# Euclidean Norm of w(t-1) - w(t)
def vecNormW(W):
    norm, vec = 0, []
    for _ in range(len(W[0])):
        vec.append(W[1][_]-W[0][_])
    for _ in range(len(vec)):
        norm += vec[_]**2
    return np.sqrt(norm)

#W = [Wt,W1]

#print(vecNormW(W))