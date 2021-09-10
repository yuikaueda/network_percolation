import numpy as np
import matplotlib.pyplot as plt

#data1 = np.loadtxt('exporamda2_center5_t1000_nbest200.dat')
data2 = np.loadtxt('gamma_k2.0_sig0.1_center5_t10000_nbest200.dat')
data3 = np.loadtxt('gamma_k3.0_sig0.1_center5_t10000_nbest200.dat')
data4 = np.loadtxt('gamma_k4.0_sig0.1_center5_t10000_nbest200.dat')
#data3 = np.loadtxt('exporamda6_center5_t1000_nbest200.dat')
#data4 = np.loadtxt('exporamda8_center5_t1000_nbest200.dat')

#l1 = data1[:,0]
#p1 = data1[:,1]

l2 = data2[:,0]
p2 = data2[:,7]

l3 = data3[:,0]
p3 = data3[:,7]

l4 = data4[:,0]
p4 = data4[:,7]

#l5 = data5[:,0]
#p5 = data5[:,1]

#l6 = data4[:,0]
#p6 = data4[:,1]

#l7 = data4[:,0]
#p7 = data4[:,1]

#l8 = data4[:,0]
#p8 = data4[:,1]

fig, axe = plt.subplots(1, 1)

#axe.plot(l1, p1, 'o', c='black', label = r'$\lambda =2$')#'$k_{on}^{c}=2,k_{off}=0.2$')
axe.plot(l2, p2, 's', markersize=4, c='gray', label = r'$k=2.0, \theta =0.1$')#'$k_{on}^{c}=5,k_{off}=0.2$')
axe.plot(l3, p3, 'v', markersize=4, c='steelblue', label = r'$k=3.0, \theta =0.1$')#'$k_{on}^{c}=10,k_{off}=0.2$')
axe.plot(l4, p4, 'p',  markersize=4, c='blueviolet', label =r'$k=4.0, \theta =0.1$')#'$k_{on}^{c}=20,k_{off}=0.2$')
#axe.plot(l5, p5, '-p',  c='yellow', label =r'$N_{s}=250$')#'$k_{on}^{c}=20,k_{off}=0.2$')
plt.xlabel("Time", fontsize = 18)
#plt.ylabel("Percolation probability", fontsize = 18)
plt.ylabel("Entropy", fontsize = 18)
#plt.ylabel("Number", fontsize = 18)
#plt.ylabel("Standard deviation", fontsize = 18)
#plt.ylim(0, 1.0)
plt.xlim([-50, 1000])


axe.legend(loc='best')
#fig.savefig("entro_n200_t10000_nbest500.png")
fig.savefig("entropy_gamma_k2.0_sig0.1_center5_t1000_nbest200.png")
plt.show()
