import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt('change_n80_a001_b5.dat')
data2 = np.loadtxt('change_n150_200_a001_b5.dat')
#data3 = np.loadtxt('long_n150_a001_b5.dat')
#data4 = np.loadtxt('long_n200_a001_b5.dat')
#data5 = np.loadtxt('change_kcon_20_070_ss_100.dat')
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

#l5 = data4[:,0]
#p5 = data4[:,1]

#l6 = data4[:,0]
#p6 = data4[:,1]

#l7 = data4[:,0]
#p7 = data4[:,1]

#l8 = data4[:,0]
#p8 = data4[:,1]

l1 = np.array(l1)
p1 = np.array(p1)
l2 = np.array(l2)
p2 = np.array(p2)

l1 = l1[l1>59]
l2 = l2[l2>59]


p1_new = []
p2_new = []
for i in range(60, 100):
    p1_i = p1[i] - p1[60]
    p2_i = p2[i] - p2[60]
    p1_new.append(p1_i)
    p2_new.append(p2_i)

fig, axe = plt.subplots(1, 1)

axe.plot(l1, p1_new, 'o-', c='black', label = r'$N_{s}=200$')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(l2, p2_new, 's-', c='red', label = r'$N_{s}=150$')#'$k_{on}^{c}=5,k_{off}=0.2$')
#axe.plot(l3, p3, 'v-', c='blue', label = r'$N_{s}=150$')#'$k_{on}^{c}=10,k_{off}=0.2$')
#axe.plot(l4, p4, '-p',  c='green', label =r'$N_{s}=200$')#'$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("time", fontsize = 18)
#plt.ylabel("Percolatin Probability", fontsize = 18)
plt.ylabel("Percolation plobability", fontsize = 18)
#plt.ylim(0, 1.1)
#plt.xlim(0, 30)

axe.legend(loc='best')
fig.savefig("seiikika_chanege_n80_150.png")
plt.show()
