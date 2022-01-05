import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import glob

def LoadComplex(file,**genfromtext_args):
    """
    Load complex data in the C++ format in numpy.
    """
    array_as_strings = np.genfromtxt(file,dtype=str,**genfromtext_args)
    complex_parser = np.vectorize(lambda x: complex(*eval(x)))
    return complex_parser(array_as_strings)

def LoadPropData(file,**genfromtext_args):
    """
    Load complex data in the C++ format in numpy.
    """
    array_as_strings = np.genfromtxt(file,dtype=str,**genfromtext_args)
    array_as_strings = array_as_strings[:,1:]
    complex_parser = np.vectorize(lambda x: complex(*eval(x)))
    return complex_parser(array_as_strings)

path_results = '../results/'
path_data = '../data/'

q = np.genfromtxt(path_data+'testQ.dat')


n_elem = q.shape[0]
n_theta = 1
theta = np.linspace(0,np.pi/2,n_theta)
'''
accF = np.zeros((n_theta,n_elem),dtype=np.complex128)

for i,file in enumerate(glob.iglob(path_results+'test.dat')):
    accF[i] = LoadComplex(file)
accF_2 = LoadComplex(path_data+'testAcc.dat')
fig = plt.figure()
ax = fig.subplots(1,1)

for i, j in enumerate(accF):
    ax.plot(q,np.abs(j)**2,label=i)
ax.plot(q,np.abs(accF_2)**2,label='2')
ax.set_yscale('log')
ax.legend(loc=0)
plt.show()
'''

accF = LoadPropData("../results/prop_acc15.dat")
vmax = 1E10
vmin = 3E0
temp = np.abs(accF)**2
fig = plt.figure(figsize=(10,4))
ax = fig.subplots(1,1)
im = ax.imshow(np.fft.fftshift(temp,axes=0),norm=matplotlib.colors.LogNorm(vmin=vmin,vmax=vmax),interpolation='gaussian',origin='lower',extent=[0,100,-1,1],aspect=50,cmap='turbo')
#ax.pcolormesh(Q,Angle/np.pi,np.fft.fftshift(temp,axes=0),norm=matplotlib.colors.LogNorm(vmin=vmin,vmax=vmax),cmap='turbo')
#ax.set_xlim(5,80)
#ax.set_ylim(-0.1,0.1)
fig.colorbar(im)


radiators = np.genfromtxt(path_results+'radiator_pos.dat')
print(radiators[0,0])
fig = plt.figure()
ax = fig.subplots(1,1)
ax.scatter(radiators[:,0],radiators[:,1])
ax.set_ylim(-1,1)
ax.set_xlim(-10,110)
plt.show()
