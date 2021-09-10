import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.optimize

data0 = np.loadtxt('div10t0.dat')
data1 = np.loadtxt('div10t500.dat')
data2 = np.loadtxt('div10t1000.dat')
data3 = np.loadtxt('div10t9500.dat')

x0 = data0[:,0]
y0 = data0[:,1]

x1 = data1[:,0]
y1 = data1[:,1]

x2 = data2[:,0]
y2 = data2[:,1]

x3 = data3[:,0]
y3 = data3[:,1]

fig, ax = plt.subplots(1, 1)

#ax.plot(x0, y0, color='palegreen', label = 't=0')
#ax.plot(x1, y1, color='sandybrown', label = 't=500')
#ax.plot(x2, y2, color='aqua', label = 't=1000')
#ax.plot(x3, y3, color='orchid', label = 't=9500')
ax.bar(x3, y3, ec='black', color='royalblue')
#ax.bar(x3, y3, ec='black', color='red', alpha=0.5)
plt.ylabel("Number", fontsize=18)
plt.xlabel("Filament number", fontsize=18)
plt.xlim(-1,20)
plt.ylim(0,70)
#ax.legend(loc='best')
fig.savefig("t9500_div10num.png")
plt.show()
