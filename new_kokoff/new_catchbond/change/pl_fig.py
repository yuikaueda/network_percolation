import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('change_kcon_20_030_l_150.dat')
data2 = np.loadtxt('change_kcon_20_050_l_150.dat')
data3 = np.loadtxt('change_kcon_20_070_l_150.dat')
data4 = np.loadtxt('change_kcon_20_090_l_150.dat')
#data5 = np.loadtxt('change_kcon_20_070_ss_100.dat')
#data6 = np.loadtxt('change_kcon_20_080_ss_100.dat')
#data7 = np.loadtxt('change_kcon_20_090_ss_100.dat')
#data8 = np.loadtxt('change_kcon_20_100_ss_100.dat')

l1 = data1[:,0]
p1 = data1[:,1]

l2 = data2[:,0]
p2 = data2[:,1]

l3 = data3[:,0]
p3 = data3[:,1]

l4 = data4[:,0]
p4 = data4[:,1]

#l5 = data4[:,0]
#p5 = data4[:,1]

#l6 = data4[:,0]
#p6 = data4[:,1]

#l7 = data4[:,0]
#p7 = data4[:,1]

#l8 = data4[:,0]
#p8 = data4[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = r'$k_{on}^{c}=0.3$')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(l2, p2, 's-', c='red', label = r'$k_{on}^{c}=0.5$')#'$k_{on}^{c}=5,k_{off}=0.2$')
axe.plot(l3, p3, 'v-', c='blue', label = r'$k_{on}^{c}=0.7$')#'$k_{on}^{c}=10,k_{off}=0.2$')
axe.plot(l4, p4, '-p',  c='green', label =r'$k_{on}^{c}=0.9$')#'$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("time", fontsize = 18)
#plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylabel("number", fontsize = 18)
#plt.ylim(0, 1.1)
#plt.xlim(0, 30)

axe.legend(loc='lower right')
fig.savefig("cha_l_150.png")
#plt.show()
