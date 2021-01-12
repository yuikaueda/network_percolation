import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('step1_kcon_10_ll_150.dat')
#data2 = np.loadtxt('kcon_kcon_10.dat')
#data3 = np.loadtxt('kcon_kcon_20.dat')
#data4 = np.loadtxt('kcon_kcon_30.dat')
#data5 = np.loadtxt('kcon_kcon_40.dat')

l1 = data1[:,0]
p1 = data1[:,1]

#l2 = data2[:,0]
#p2 = data2[:,1]

#l3 = data3[:,0]
#p3 = data3[:,1]

#l4 = data4[:,0]
#p4 = data4[:,1]

#l5 = data5[:,0]
#p5 = data5[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = r'$k_{on}^{c}/{k_{on}^{0}}=2$')#'$k_{on}^{c}=2,k_{off}=0.2$')
#axe.plot(l2, p2, 's-', c='red', label = r'$k_{on}^{c}/{k_{on}^{0}}=10$')#'$k_{on}^{c}=5,k_{off}=0.2$')
#axe.plot(l3, p3, 'v-', c='blue', label = r'$k_{on}^{c}/{k_{on}^{0}}=20$')#'$k_{on}^{c}=10,k_{off}=0.2$')
#axe.plot(l4, p4, 'p-',  c='green', label =r'$k_{on}^{c}/{k_{on}^{0}}=30$')#'$k_{on}^{c}=20,k_{off}=0.2$')
#axe.plot(l5, p5, '^-',  c='yellow', label =r'$k_{on}^{c}/{k_{on}^{0}}=40$')#'$k_{on}^{c}=20,k_{off}=0.2$')

plt.xlabel("time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
#plt.ylabel("number", fontsize = 18)
#plt.ylim(0, 1.1)
#plt.xlim(0, 30)

#axe.legend(loc='lower right')
fig.savefig("step1_kcon10.png")
#plt.show()
