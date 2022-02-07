import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('long_n80_a001_b5.dat')
#data2 = np.loadtxt('long_n100_a001_b5.dat')
#data3 = np.loadtxt('long_n150_a001_b5.dat')
#data4 = np.loadtxt('long_n200_a001_b5.dat')
#data5 = np.loadtxt('change_kcon_20_070_ss_100.dat')
#data6 = np.loadtxt('change_kcon_20_080_ss_100.dat')
#data7 = np.loadtxt('change_kcon_20_090_ss_100.dat')
#data8 = np.loadtxt('change_kcon_20_100_ss_100.dat')

t1 = data1[:,0]
n1 = data1[:,2]

t2 = data1[:,0]
n2 = data1[:,3]

#l3 = data3[:,0]
#p3 = data3[:,1]

#l4 = data4[:,0]
#p4 = data4[:,1]

#l5 = data4[:,0]
#p5 = data4[:,1]

#l6 = data4[:,0]
#p6 = data4[:,1]

#l7 = data4[:,0]
#p7 = data4[:,1]

#l8 = data4[:,0]
#p8 = data4[:,1]

fig, axe = plt.subplots(1, 1)

axe.plot(t1, n1, 'o-', c='black', label = r'$SF$')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(t2, n2, 's-', c='red', label = r'$Mesh$')#'$k_{on}^{c}=5,k_{off}=0.2$')
#axe.plot(l3, p3, 'v-', c='blue', label = r'$N_{best}=150$')#'$k_{on}^{c}=10,k_{off}=0.2$')
#axe.plot(l4, p4, '-p',  c='green', label =r'$N_{best}=200$')#'$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("Time", fontsize = 18)
#plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylabel("Number", fontsize = 18)
#plt.ylim(0, 1.1)
#plt.xlim(0, 30)

axe.legend(loc='best')
fig.savefig("re_Number80_a001b5.png")
plt.show()
