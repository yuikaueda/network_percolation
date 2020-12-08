import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('kon08_koff02.dat')
#data2 = np.loadtxt('kon05_koff05.dat')
#data3 = np.loadtxt('kon06_koff04.dat')
#data4 = np.loadtxt('kon05_koff05.dat')

l1 = data1[:,0]
p1 = data1[:,1]

#l2 = data2[:,0]
#p2 = data2[:,1]

#l3 = data3[:,0]
#p3 = data3[:,1]

#l4 = data4[:,0]
#p4 = data4[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = '$k_{on}=0.8,k_{off}=0.2$')
#axe.plot(l2, p2, 's-', c='red', label = '$k_{on}=0.5,k_{off}=0.5$')
#axe.plot(l3, p3, 'v-', c='blue', label = '$k_{on}=0.6,k_{off}=0.4$')
#axe.plot(l4, p4, '-p',  c='green', label = '$k_{on}=0.5,k_{off}=0.5$')
plt.xlabel("time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylim(0, 1)
plt.xlim(0, 30)

axe.legend()
fig.savefig("p_time30_kokoff.png")
#plt.show()
