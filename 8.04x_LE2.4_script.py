import numpy as np

def getNorm(u):
    u_star = np.conjugate(u)
    matrix = np.array([[1/np.sqrt(2), u],[-u_star, 1/np.sqrt(2)]])
    vector = np.array([[1/np.sqrt(2)] for i in range(2)])
    result = matrix @ vector
    return result[0]**2 + result[1]**2

print("u = e^jδ")
for i in range(5):
    d = np.random.randint(-1000, 1000)
    u = np.e**(1j * d)
    P = getNorm(u)
    print("P: {} δ: {}".format(P, d))

print("\nu = ±1/√2")
for i in range(2):
    u = (-1+2*i) * 1 / np.sqrt(2)
    P = getNorm(u)
    print("P: {}".format(P))

print("\nu = 1/√2 * e^jδ; δ € R")
for i in range(5):
    d = np.random.randint(-1000, 1000)
    u = 1/np.sqrt(2) * np.e**(1j * d)
    P = getNorm(u)
    print("P: {} δ: {}".format(P, d))

print("\nu = ±j/√2")
for i in range(2):
    u = (-1+2*i) * 1 / np.sqrt(2)
    P = getNorm(u)
    print("P: {}".format(P))
