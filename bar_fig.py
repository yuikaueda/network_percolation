import numpy as np
import matplotlib.pyplot as plt

left = np.array([0.1, 0.2, 0.3,0.4, 0.5, 0.6, 0.7, 0.8])
height = np.array([60, 40, 20, 20, 10, 6, 2, 1])

fig, ax = plt.subplots(1, 1)

plt.bar(left, height,width=0.06, align="center")

plt.ylim(0,80)
plt.xlabel("length", fontsize = 18)
plt.ylabel("n", fontsize = 18)

fig.savefig("pb1_fig.png")
#plt.show()
