import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math
import scipy.special as sps

df = np.loadtxt('len_gamma_k2.0_sig0.1.dat')
#df1 = df.round(2)

N= 221
k = 2.0
sig = 0.1
x = np.linspace(0,1,100)
y =  x**(k-1)*(np.exp(-x/sig) / (sps.gamma(k)*sig**k))

fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1)
ax2 = ax1.twinx()

ret = ax1.hist(df, bins=10, range=(0.0,0.7), histtype='barstacked', ec='black', color='lightcoral')
#ret1 = list(ret)
#ret1[0] = ret1[0]/491
print(ret[1])
#file = open('hist_data.dat','w')
#file.writelines(str(ret))
#file.close()

ax2.plot(x, y, '-', c='black', label =r'$k=2.0, \theta =0.1$')
ax1.set_xlabel(r"Filament length", fontsize = 18)
ax1.set_ylabel(r"Number", fontsize = 18)
ax2.set_ylabel(r"PDF", fontsize = 18)
plt.xlim([0,0.7])
ax1.set_ylim([0,200])
ax2.set_ylim([0,10])
ax2.legend(loc='best')
#filename = f'hist_gamma_k{k}_sig{sig}.png'
fig.savefig(f'colar_hist_gamma_N{N}_k{k}_sig{sig}.png')
plt.show()
