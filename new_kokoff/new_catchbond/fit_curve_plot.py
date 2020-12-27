from scipy.optimize import curve_fit
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

data1 = np.loadtxt('kcon_20.dat')
data2 = np.loadtxt('kcon_20.dat')
data3 = np.loadtxt('kcon_20.dat')
data4 = np.loadtxt('kcon_20.dat')
data5 = np.loadtxt('kcon_20.dat')

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

param1, cov1 = curve_fit(fit, x1, y1)
param2, cov2 = curve_fit(fit, x2, y2)
param3, cov3 = curve_fit(fit, x3, y3)
param4, cov4 = curve_fit(fit, x4, y4)
param5, cov5 = curve_fit(fit, x5, y5)

print(param)

y_fit = []
for num in x1:
    y_fit.append(param[0]*(1-np.exp(-num/param[1])))
array_y_fit = np.array(y_fit)

fig, axe = plt.subplots(1, 1)
axe.plot(x1, y1, 'o', c='red', label = 'data')#'$k_{on}^{c}=2,k_{off}=    0.2$')
axe.plot(x1, array_y_fit, '-', c='black', label = 'fit')
plt.xlabel("time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
fig.savefig("fit_kcon_20.png")
  
#sns.pointplot(x=x1, y=y1, join=False)
#sns.pointplot(x=x1, y=array_y_fit, markers="")

#plt.show()
