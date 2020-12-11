import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('change_kcon_20_s.dat')
data2 = np.loadtxt('change_kcon_20_l.dat')
#data3 = np.loadtxt('kcon_10.dat')
#data4 = np.loadtxt('kcon_20.dat')

l1 = data1[:,0]
p1 = data1[:,1]

l2 = data2[:,0]
p2 = data2[:,1]

#l3 = data3[:,0]
#p3 = data3[:,1]

#l4 = data4[:,0]
#p4 = data4[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = 'shorter')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(l2, p2, 's-', c='red', label = 'longer')#'$k_{on}^{c}=5,k_{off}=0.2$')
#axe.plot(l3, p3, 'v-', c='blue', label = '$k_{on}^{c}=10,k_{off}=0.2$')
#axe.plot(l4, p4, '-p',  c='green', label = '$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylim(0, 1)
#plt.xlim(0, 30)

axe.legend(loc='lower right')
fig.savefig("cha_p_time_kcon_length.png")
#plt.show()
