# 6.004.1x Exam
# 4.1 Combinational Logic
# Wayne H Noxchi - 14-Nov-2016 20:38

def INV(X):
    if X == 1:
        return 0
    else:
        return 1
def AND(X, Y):
    if (X == Y) and X == 1:
        return 1
    else:
        return 0
def OR(X,Y):
    if X == 1 or Y == 1:
        return 1
    else:
        return 0
def NOR(X,Y):
    return INV(OR(X,Y))
def NAND(X,Y):
    return INV(AND(X,Y))

def Z(A,B,C):
    return OR(INV(NAND(A, INV(B))), NOR(A, AND(B, C)))

for i in range(2):
    for j in range(2):
        for k in range(2):
            print Z(i,j,k)
