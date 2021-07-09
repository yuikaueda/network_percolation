import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
#from mpl_toolkits.axes_grid1 import make_axes_locatable
import scipy.optimize

df = pd.read_table('ndis_t1000_nbest250.dat')
print(df.columns.tolist())
df_pivot = pd.pivot_table(data=df, values='c', columns='y', index='x', aggfunc=np.mean)

fig, ax = plt.subplots(1, 1)
mappable = ax.pcolor(df_pivot.columns, df_pivot.index, df_pivot.T)
fig.colorbar(mappable, ax=ax)
fig.tight_layout()

fig.savefig("c_t1000_nbest250.png")
plt.show()
