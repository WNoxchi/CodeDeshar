#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov 29 21:35:05 2016

@author: WayNoxchi
"""
import random
def throwNeedles(numNeedles):
    success = 0
    for n in range(numNeedles):
        x = random.random()
        if (1+x)**2 < 2.0:
            success += 1
    sqrt2 = 1 + (float(success)/numNeedles)
    return sqrt2
    