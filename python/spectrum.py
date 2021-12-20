import numpy as np
import matplotlib.pyplot as plt
import glob

def LoadComplex(file,**genfromtext_args):
    """
    Load complex data in the C++ format in numpy.
    """
    array_as_strings = np.genfromtxt(file,dtype=str,**genfromtext_args)
    complex_parser = np.vectorize(lambda x: complex(*eval(x)))
    return complex_parser(array_as_strings)



path_results = '../results/'
path_data = '../data/'

q = np.genfromtxt(path_data+'testQ.dat')


n_elem = q.shape[0]
n_theta = 1
theta = np.linspace(0,np.pi/2,n_theta)
accF = np.zeros((n_theta,n_elem),dtype=np.complex128)

for i,file in enumerate(glob.iglob(path_results+'interpacc.dat')):
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



radiators = np.genfromtxt(path_results+'radiator_pos.dat')
print(radiators[0,0])
fig = plt.figure()
ax = fig.subplots(1,1)
ax.scatter(radiators[:,0],radiators[:,1])
ax.set_ylim(-1,1)
ax.set_xlim(-10,110)
plt.show()
