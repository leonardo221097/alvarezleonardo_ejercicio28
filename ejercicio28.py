import numpy as np
import matplotlib.pylab as plt




data=np.loadtxt('ejercicio28.dat')
x=data[:,1]
y=data[:,2]

plt.plot(x,y)
plt.savefig('ejercicio28.png')
 