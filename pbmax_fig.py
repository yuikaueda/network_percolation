import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('pb0_160.dat')
data2 = np.loadtxt('pb1_160.dat')

l1 = data1[:,0]
p1 = data1[:,1]

l2 = data2[:,0]
p2 = data2[:,1]


fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = 'patarn0')
axe.plot(l2, p2, 's-', c='red', label = 'patarn1')
plt.xlabel("b_max", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)

axe.legend()
fig.savefig("pb_12.png")
#plt.show()
