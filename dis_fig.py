import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('dis0_N8_90.dat')

x1 = data[:,0]
x2 = data[:,1]
y1 = data[:,2]
y2 = data[:,3]

fig, axe = plt.subplots(1,1)

plt.plot([x1,x2],[y1,y2],lw=0.5,c='green')

plt.xlim([0.3,1])
plt.ylim([0.3,1])

axe.axes.xaxis.set_ticks([])
axe.axes.yaxis.set_ticks([])
axe.set_aspect('equal')

fig.savefig("dis0_N8_90.png")
#plt.show()
