import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('pp_01.dat')
data2 = np.loadtxt('pp_02.dat')
data3 = np.loadtxt('pp_03.dat')
data4 = np.loadtxt('pp_04.dat')

b1 = data1[:,0]
p1 = data1[:,1]

b2 = data2[:,0]
p2 = data2[:,1]

b3 = data3[:,0]
p3 = data3[:,1]

b4 = data4[:,0]
p4 = data4[:,1]

fig, ax = plt.subplots(1, 1)

ax.plot(b1, p1, 'o-', c='black', label = 'l=0.1')
ax.plot(b2, p2, 's-', c='red', label = 'l=0.2')
ax.plot(b3, p3, 'v-', c='blue', label = 'l=0.3')
ax.plot(b4, p4, 'p-', c='green', label = 'l=0.4')

plt.xlabel("b_max", fontsize = 18)
plt.ylabel("Cluster Percolation Probability", fontsize = 18)

ax.legend()
fig.savefig("pp.png")
