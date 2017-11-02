# WNixalo 2017-Oct-12 21:29 8.04x
import numpy as np

M1 = np.array([[1/np.sqrt(2),1/np.sqrt(2)],
               [0.5,-0.5],
               [-0.5,0.5]])

M2 = np.array([[1/np.sqrt(2),1/np.sqrt(2)],
               [0.5,-0.5],
               [0.5,-0.5]])

M3 = np.array([[1/np.sqrt(2),1/np.sqrt(2)],
               [1j/2,-1j/2],
               [1j/2,-1j/2]])

M4 = np.array([[1/np.sqrt(2),1/np.sqrt(2)],
               [1j/2,-1j/2],
               [-1j/2,1j/2]])

Ms = [M1,M2,M3,M4]

# a = 1/np.sqrt(2); b = a
# a = 1; b = 0
a = 0; b = 1
amp_in = np.array([[a],[b]])
amp_out= np.array([[a*(a+b)],[0.5*(a-b)],[0.5*(a-b)]])

for m in Ms:
    amp_temp = m @ amp_in
    print(amp_out)
    print(amp_temp)
    print()
