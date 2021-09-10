import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('recenter5_t10000_nbest200.dat')
data2 = np.loadtxt('recenter5_t10000_nbest500.dat')
#data3 = np.loadtxt('long_n150_a001_b5.dat')
#data4 = np.loadtxt('long_n200_a001_b5.dat')
#data5 = np.loadtxt('long_n250_a001_b5.dat')
#data6 = np.loadtxt('change_kcon_20_080_ss_100.dat')
#data7 = np.loadtxt('change_kcon_20_090_ss_100.dat')
#data8 = np.loadtxt('change_kcon_20_100_ss_100.dat')

l1 = data1[:,0]
p1 = data1[:,6]

l2 = data2[:,0]
p2 = data2[:,6]

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

axe.plot(l1, p1, 'o', markersize=2, c='deeppink', label = r'$N_{s}=200$')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(l2, p2, 's', markersize=2, c='mediumblue', label = r'$N_{s}=500$')#'$k_{on}^{c}=5,k_{off}=0.2$')
#axe.plot(l3, p3, 'v-', c='seagreen', label = r'$N_{s}=150$')#'$k_{on}^{c}=10,k_{off}=0.2$')
#axe.plot(l4, p4, '-p',  c='green', label =r'$N_{s}=200$')#'$k_{on}^{c}=20,k_{off}=0.2$')
#axe.plot(l5, p5, '-p',  c='yellow', label =r'$N_{s}=250$')#'$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("Time", fontsize = 18)
#plt.ylabel("Percolation probability", fontsize = 18)
#plt.ylabel("Entropy", fontsize = 18)
#plt.ylabel("Number", fontsize = 18)
plt.ylabel("Standard deviation", fontsize = 18)
#plt.ylim(0, 1)
#plt.xlim(0, 30)

axe.legend(loc='best')
#fig.savefig("entro_n200_t10000_nbest500.png")
fig.savefig("sd55_t10000_nbest200and500.png")
plt.show()
