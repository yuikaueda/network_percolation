from scipy.optimize import curve_fit
import numpy as np
#import seaborn as sns
import matplotlib.pyplot as plt

data1 = np.loadtxt('kcon_kcon_50.dat')

def fit(x,K,T):
    return K*(1-np.exp(-x/T))

x1 = data1[:,0]
y1 = data1[:,1]

param, cov = curve_fit(fit, x1, y1)
print(param)

y_fit = []
for num in x1:
    y_fit.append(param[0]*(1-np.exp(-num/param[1])))
array_y_fit = np.array(y_fit)

fig, axe = plt.subplots(1, 1)
axe.plot(x1, y1, 'o', c='red', label = 'data')#'$k_{on}^{c}=2,k_{off}=    0.2$')
axe.plot(x1, array_y_fit, '-', c='black', label = r'$P={}(1-exp(-t/{}))$'.format(param[0].round(3),param[1].round(3)))
plt.xlabel("time", fontsize = 18)
plt.ylabel("Percolatin Probability", fontsize = 18)
axe.legend()
fig.savefig("fit_kcon_50.png")
  
#sns.pointplot(x=x1, y=y1, join=False)
#sns.pointplot(x=x1, y=array_y_fit, markers="")

#plt.show()
