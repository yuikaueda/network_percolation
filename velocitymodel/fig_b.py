import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('petern_ab01.dat')

t = data1[:,0]
p_a = data1[:,1]
p_b = data1[:,2]

fig, axe = plt.subplots(1, 1)

axe.plot(t, p_a, 'o-', c='black', label = 'a')
axe.plot(t, p_b, 's-', c='red', label = 'b')
plt.xlabel("Time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylim([0,0.6])

axe.legend()
fig.savefig("petern_ab01.png")

