# 6.004.1x Computation Structures 1: Digital Circuits
# Wayne Hakan Nixalo  -   14-Nov-2016 19:03
# Huffman Encoding Generator ------------------------

import numpy as np
probs = [['O',0.41],['E',0.11],['A',0.07],['P',0.19],['D',0.14],['T',0.08]]
def Huffman(probs):
    min1, min2 = ['',1], ['',1]
    for i in range(probs):
        if probs[i][1] < min1[1]:
            min2 = min1
            min1 = probs[i]
    print ("branches: {}".format([min1, min2]))
    node = [min1[0] + min2[0], min1[1] + min2[1]]
    kerlotree = probs
    for i in range(len(kerlotree)):
        if kerlotree[i][0] == min1[0]:
            kerlotree[i].remove()
        elif kerlotree[i][0] == min2[0]:
            kerlotree[i].remove()
    kerlotree.append(node)
    return kerlotree

print (probs)
while len(probs) > 1:
    probs = Huffman(probs)
    print (probs)
