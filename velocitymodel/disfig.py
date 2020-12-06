import numpy as np
import matplotlib.pyplot as plt
import matplotlib.collections as mc
data = np.loadtxt('test.dat')

x1 = data[:,0]
x2 = data[:,1]
y1 = data[:,2]
y2 = data[:,3]
color = data[:,4]

fig, axe = plt.subplots(1,1)

for i in range(len(x1)):
    lines = [[(x1[i], y1[i]), (x2[i], y2[i])]]
    lc = mc.LineCollection(lines, lw = 0.5, colors = 'C{}'.format(int(color[i])))
    axe.add_collection(lc)
#plt.plot([x1,x2],[y1,y2],lw=0.5,c='C{}'.format(color))

plt.xlim([0,1])
plt.ylim([0,1])

axe.axes.xaxis.set_ticks([])
axe.axes.yaxis.set_ticks([])
axe.set_aspect('equal')

fig.savefig("test.png")
#plt.show()
