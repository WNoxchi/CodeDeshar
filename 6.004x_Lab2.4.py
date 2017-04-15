# 6.004.1x - Computation Structures
# Lab 2.4: Design Problem: 3-bit Adder
# WNixalo - 30-Nov-2016 16:25
def AND(x,y):
    return x and y
def OR(x,y):
    return x or y
def NOT(x):
    return not x
def NOR(x,y):
    return not OR(x,y)
def NAND(x,y):
    return not AND(x,y)
    
def OR3(x,y,w):
    return x or y or w

def Z(X,Y,W):
    if NAND(NAND(X,Y),W):
        return 1
    else:
        return 0

def J(X,Y,W):
    if NOT(AND(W,OR(NOT(X),NOT(Y)))):
        return 1
    else:
        return 0
        
def NCO2(x,y):
    if NAND(NAND(x,x),NAND(y,y)):
        return 1
    else:
        return 0
        
def NAND3(x,y,w):
#    return not(x and y and w)
    if not(x and y and w):
        return 1
    else:
        return 0

def NCO3(x,y,w):
    if NCO2(NCO2(x,y),w):
        return 1
    else:
        return 0
        
def NaOR3(x,y,w):
    if NAND3(NAND3(x,x,x),NAND3(y,y,y),NAND3(w,w,w)):
        return 1
    else:
        return 0

for x in range(2):
    X = x
    for y in range(2):
        Y = y
        for w in range(2):
            W = w
#            print('{} {} {} | {} / {}'.format(X,Y,W,OR(Y,W),NCO2(Y,W)))
#            print('{} {} {} | {} / {}'.format(X,Y,W,OR3(X,Y,W),NCO3(X,Y,W)))
#            print('{} {} {} | {} / {}'.format(X,Y,W,OR3(X,Y,W),NaOR3(X,Y,W)))
            print('{} {} {} | {}'.format(X,Y,W, NAND3(X,Y,W)))
                  