from scipy.optimize import curve_fit
import numpy as np
#import seaborn as sns
import matplotlib.pyplot as plt

data1 = np.loadtxt('kcon_kcon_2.dat')
data2 = np.loadtxt('kcon_kcon_6.dat')
data3 = np.loadtxt('kcon_kcon_10.dat')
data4 = np.loadtxt('kcon_kcon_14.dat')
data5 = np.loadtxt('kcon_kcon_18.dat')
data6 = np.loadtxt('kcon_kcon_22.dat')
data7 = np.loadtxt('kcon_kcon_26.dat')
data8 = np.loadtxt('kcon_kcon_30.dat')
data9 = np.loadtxt('kcon_kcon_34.dat')
data10 = np.loadtxt('kcon_kcon_38.dat')
data11 = np.loadtxt('kcon_kcon_42.dat')
data12 = np.loadtxt('kcon_kcon_46.dat')
data13 = np.loadtxt('kcon_kcon_50.dat')

def fit(x,K,T):
    return K*(1-np.exp(-x/T))

x1 = data1[:,0]
y1 = data1[:,1]

x2 = data2[:,0]
y2 = data2[:,1]

x3 = data3[:,0]
y3 = data3[:,1]

x4 = data4[:,0]
y4 = data4[:,1]

x5 = data5[:,0]
y5 = data5[:,1]

x6 = data6[:,0]
y6 = data6[:,1]

x7 = data7[:,0]
y7 = data7[:,1]

x8 = data8[:,0]
y8 = data8[:,1]

x9 = data9[:,0]
y9 = data9[:,1]

x10 = data10[:,0]
y10 = data10[:,1]

x11 = data11[:,0]
y11 = data11[:,1]

x12 = data12[:,0]
y12 = data12[:,1]

x13 = data13[:,0]
y13 = data13[:,1]

param1, cov1 = curve_fit(fit, x1, y1)
param2, cov2 = curve_fit(fit, x2, y2)
param3, cov3 = curve_fit(fit, x3, y3)
param4, cov4 = curve_fit(fit, x4, y4)
param5, cov5 = curve_fit(fit, x5, y5)
param6, cov6 = curve_fit(fit, x6, y6)
param7, cov7 = curve_fit(fit, x7, y7)
param8, cov8 = curve_fit(fit, x8, y8)
param9, cov9 = curve_fit(fit, x9, y9)
param10, cov10 = curve_fit(fit, x10, y10)
param11, cov11 = curve_fit(fit, x11, y11)
param12, cov12 = curve_fit(fit, x12, y12)
param13, cov13 = curve_fit(fit, x13, y13)

#y_K = [param1[0],param2[0],param3[0],param4[0],param5[0],param6[0],param7[0],param8[0],param9[0],param10[0],param11[0],param12[0],param13[0]]
y_K = [param1[1],param2[1],param3[1],param4[1],param5[1],param6[1],param7[1],param8[1],param9[1],param10[1],param11[1],param12[1],param13[1]]
x = [2,6,10,14,18,22,26,30,34,38,42,46,50]
#print(param)

#y_fit = []
#for num in x1:
    #y_fit.append(param[0]*(1-np.exp(-num/param[1])))
#array_y_fit = np.array(y_fit)

fig, axe = plt.subplots(1, 1)
fig.subplots_adjust(bottom=0.15)
axe.plot(x, y_K, 'o', c='black', label = 'data')#'$k_{on}^{c}=2,k_{off}=    0.2$')
#axe.plot(x1, array_y_fit, '-', c='black', label = 'fit')
plt.xlabel(r'$k^{c} _{on}/k^{0} _{on}$', fontsize = 18)
plt.ylabel("parameter T", fontsize = 18)
#plt.ylim(0,1.1)
fig.savefig("fit_parameter_1.png")
  
#sns.pointplot(x=x1, y=y1, join=False)
#sns.pointplot(x=x1, y=array_y_fit, markers="")

#plt.show()
