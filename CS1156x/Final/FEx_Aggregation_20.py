# CS1156x - Learning from Data
# Wayne H Nixalo - 2017-Apr-07 17:38

# target function
f = lambda x : -x

# learned hyp 1
g1 = lambda x : 0.5 * x
g2 = lambda x : -0.25 * x

g = lambda x : 0.5 * (g1(x) + g2(x))

import numpy as np

x = np.random.uniform(-1,1, (100))
y = np.zeros(100)
for i in range(len(x)):
    y[i] = f(x[i])

# Eout g1
g1y = np.zeros(len(x))
for i in range(len(x)): g1y[i] = g1(x[i])
g1_Eout = 0
for i in range(len(x)):
    if np.sign(g1y[i]) != np.sign(y[i]):
        g1_Eout += 1
g1_Eout /= len(x)

# Eout g2
g2y = np.zeros(len(x))
for i in range(len(x)): g2y[i] = g2(x[i])
g2_Eout = 0
for i in range(len(x)):
    if np.sign(g2y[i]) != np.sign(y[i]):
        g2_Eout += 1
g2_Eout /= len(x)

# Eout g
gy = np.zeros(len(x))
for i in range(len(x)): gy[i] = g(x[i])
g_Eout = 0
for i in range(len(x)):
    if np.sign(gy[i]) != np.sign(y[i]):
        g_Eout += 1
g_Eout /= len(x)

print("g1 Eout: {}\ng2 Eout: {}\ng Eout: {}\n".format(g1_Eout, g2_Eout, g1_Eout))
