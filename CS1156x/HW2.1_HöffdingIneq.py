# -*- coding: utf-8 -*-
# Wayne H Nixalo - CS1156x Learning from Data - HW2.1 Höffding Inequality - 20 Oct 2016
import numpy as np
import random
#Heads = 1, Tails = 0
Result = [['C1|V1:', 0],['CR|VR:', 0],['Cmin|Vmin:', 0]]
for k in range(100000):
    Coins = []
    for _ in range(1000): Coins.append([])
    for _ in range(10):
        for i in range(1000):
            Coins[i].append(np.random.randint(0,2))
    Vmin = 2
    for _ in range(1000):
        if Vmin > float(sum(Coins[_]))/10:
            Vmin = float(sum(Coins[_]))/10
    C1 = Coins[0]
    V1 = float(sum(Coins[0]))/10
    indexR = np.random.randint(0,1000)
    CR = Coins[indexR]
    VR = float(sum(Coins[indexR]))/10

    Result[0][1] += V1
    Result[1][1] += VR
    Result[2][1] += Vmin

    if k%1500 == 0:
        print(repr(k/float(1000)) + '% complete')

for _ in range(3):
    Result[_][1] = float(Result[_][1])/100000

print(Result)
