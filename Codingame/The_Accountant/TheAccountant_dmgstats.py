import numpy as np
import matplotlib.pyplot as plt

x = []
n = 1990
for i in range(1600):
    x.append(np.around(float(125000)/(n**1.2)))
    plt.plot(n, x[i], 'bo')
    n += 10
plt.axis([1980,16600,0,20])
plt.show()