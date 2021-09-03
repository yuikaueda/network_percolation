import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math

df = np.loadtxt('len_ramda10.dat')
#df1 = df.round(2)

x = np.linspace(0,1,100)
y = 10*np.exp(-10*x)

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

ret = ax.hist(df, bins=10, density = True, range=(0.0,0.7), histtype='barstacked', ec='black', color='coral')
#ret1 = list(ret)
#ret1[0] = ret1[0]/491
print(ret[1])
#file = open('hist_data.dat','w')
#file.writelines(str(ret))
#file.close()

ax.plot(x, y, '-', c='black', label =r'$y=10exp(-10x)$')
plt.xlabel(r"Filament length", fontsize = 18)
plt.ylabel(r"Number", fontsize = 18)
plt.xlim([0,0.7])
plt.ylim([0,10])
ax.legend(loc='best')
fig.savefig("hist_len_ramda10.png")
plt.show()
