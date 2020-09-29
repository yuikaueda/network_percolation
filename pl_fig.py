import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('pl_10.dat')
data2 = np.loadtxt('pl_30.dat')
data3 = np.loadtxt('pl_60.dat')
data4 = np.loadtxt('pl_90.dat')

l1 = data1[:,0]
p1 = data1[:,1]

l2 = data2[:,0]
p2 = data2[:,1]

l3 = data3[:,0]
p3 = data3[:,1]

l4 = data4[:,0]
p4 = data4[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = 'theta=10')
axe.plot(l2, p2, 's-', c='red', label = 'theta=30')
axe.plot(l3, p3, 'v-', c='blue', label = 'theta=60')
axe.plot(l4, p4, 'p-', c='green', label = 'theta=90')
plt.xlabel("L", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)

axe.legend()
fig.savefig("pl_theta.png")
#plt.show()
