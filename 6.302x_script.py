from sympy import *

T = Symbol('T') #create 'T' symbol
m = Symbol('m') #create 'm' symbol
Kp = Symbol('Kp') #create 'Kp' symbol
Kp = 50
Kd = 10

m = 10000
T = 0.01

A = Matrix([[1,T],[0,1]]) #A matrix
B = Matrix([[0],[T/m]]) #B matrix
C = Matrix([[1,0]]) #C matrix
K = Matrix([[Kp,Kd]]) #K matrix

print("Open Loop Natural Frequencies/Eigenvalues:")
print(A.eigenvals())
print("Closed Loop Natural Frequencies/Eigenvalues:")
M = A - B*K #calculate closed loop state transition matrix
print("Matrix M = A - B*K:")
print(M)

print(M.eigenvals())
print("Ku Value:")
Ku = (C*(eye(2)-A + B*K)**(-1)*B)**(-1) #calculate input scaling gain
print(Ku)

