import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('change_n200_t10000_nbesti80_nbestc150.dat')
data2 = np.loadtxt('change_n200_t10000_nbesti80_nbestc500.dat')
#data3 = np.loadtxt('long_n150_a001_b5.dat')
#data4 = np.loadtxt('long_n200_a001_b5.dat')
#data5 = np.loadtxt('long_n250_a001_b5.dat')
#data6 = np.loadtxt('change_kcon_20_080_ss_100.dat')
#data7 = np.loadtxt('change_kcon_20_090_ss_100.dat')
#data8 = np.loadtxt('change_kcon_20_100_ss_100.dat')

l1 = data1[:,0]
p1 = data1[:,1]

l2 = data2[:,0]
p2 = data2[:,1]

#l3 = data3[:,0]
#p3 = data3[:,1]

#l4 = data4[:,0]
#p4 = data4[:,1]

#l5 = data5[:,0]
#p5 = data5[:,1]

#l6 = data4[:,0]
#p6 = data4[:,1]

#l7 = data4[:,0]
#p7 = data4[:,1]

#l8 = data4[:,0]
#p8 = data4[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1, 'o-', c='black', label = r'$N_{s}=150$')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(l2, p2, 's-', c='red', label = r'$N_{s}=500$')#'$k_{on}^{c}=5,k_{off}=0.2$')
#axe.plot(l3, p3, 'v-', c='blue', label = r'$N_{s}=150$')#'$k_{on}^{c}=10,k_{off}=0.2$')
#axe.plot(l4, p4, '-p',  c='green', label =r'$N_{s}=200$')#'$k_{on}^{c}=20,k_{off}=0.2$')
#axe.plot(l5, p5, '-p',  c='yellow', label =r'$N_{s}=250$')#'$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("Time", fontsize = 18)
#plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylabel("Percolation probability", fontsize = 18)
#plt.ylim(0, 1.1)
plt.xlim(5900,6500)

axe.legend(loc='best')
fig.savefig("ch_n200_t10000_80tobest.png")
plt.show()
