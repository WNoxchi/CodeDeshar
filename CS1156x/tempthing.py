# Reference: http://nbviewer.jupyter.org/github/tournami/Learning-From-Data-MOOC/blob/master/Homework%204.html

from scipy.misc import comb
import numpy as np
import matplotlib.pyplot as plt

maxN = 1000
q = 1

mH_list = np.zeros(maxN)
mH = 2
for N in range(1, maxN + 1):
    mH = 2 * mH - comb(N, q)
    mH_list[N-1] = mH

q1_col = np.log(mH_list)

dvc_1 = np.log(np.arange(2, 1002)**1)

Thing = []
for i in range(maxN):
    Thing.append([q1_col[i],dvc_1[i]])
print Thing

names = ["q=1 col","dvc=1 col"]

N = np.arange(2,1002)

plt.xlabel("N")
plt.plot(N, q1_col)
plt.plot(N, dvc_1)
plt.legend(names, loc="best")
plt.show()

#############################

from scipy.misc import comb
import numpy as np
import matplotlib.pyplot as plt

def make_mH_column(q, maxN=1000):
    """Creates a column of mHs based on q and N"""

    mH_list = np.zeros(maxN)

    mH = 2
    for N in range(1, maxN+1):
        mH = 2 * mH - comb(N, q)
        mH_list[N-1] = mH

    return mH_list
# make q columns
q_1_column = np.log(make_mH_column(q=1))
q_2_column = np.log(make_mH_column(q=2))
q_3_column = np.log(make_mH_column(q=3))
q_4_column = np.log(make_mH_column(q=4))
q_5_column = np.log(make_mH_column(q=5))

q_list = [q_1_column, q_2_column, q_3_column, q_4_column, q_5_column]

# make dvc columns
dvc_1 = np.log(np.arange(2,1002)**1)
dvc_2 = np.log(np.arange(2,1002)**2)
dvc_3 = np.log(np.arange(2,1002)**3)
dvc_4 = np.log(np.arange(2,1002)**4)
dvc_5 = np.log(np.arange(2,1002)**5)

dvc_list = [dvc_1, dvc_2, dvc_3, dvc_4, dvc_5]
title = "$mH$ bounds for $q = {}$"

q = 1
plt.title(title.format(q))
plt.plot(np.arange(1,1001), q_list[q-1], label="$q = {}$".format(q))
for dvc in np.arange(1,6):
    plt.plot(np.arange(1,1001), dvc_list[dvc-1], label="$N^{}$".format(dvc))
plt.legend(loc="best")

plt.show()
