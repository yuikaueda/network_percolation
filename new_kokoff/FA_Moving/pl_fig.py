import numpy as np
import matplotlib.pyplot as plt

#data1 = np.loadtxt('onestep_kfa_1.dat')
#data2 = np.loadtxt('onestep_kfa_10.dat')
#data3 = np.loadtxt('onestep_kfa_30.dat')
data4 = np.loadtxt('onestep_kfa_50.dat')

#l1 = data1[:,0]
#p1 = data1[:,1]

#l2 = data2[:,0]
#p2 = data2[:,1]

#l3 = data3[:,0]
#p3 = data3[:,1]

l4 = data4[:,0]
p4 = data4[:,1]

fig, axe = plt.subplots(1, 1)

#axe.plot(l1, p1, 'o-', c='black', label = '$k_{on}/{k_{off}}=1$')
#axe.plot(l2, p2, 's-', c='red', label = '$k_{on}/{k_{off}}=10$')
#axe.plot(l3, p3, 'v-', c='blue', label = '$k_{on}/{k_{off}}=30$')
axe.plot(l4, p4, '-p',  c='green', label = '$k_{on}/{k_{off}}=50$')
plt.xlabel("time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylim(0, 1.1)
#plt.xlim(0, 30)

axe.legend()
fig.savefig("onestep_p_time_kfa_50.png")
#plt.show()
