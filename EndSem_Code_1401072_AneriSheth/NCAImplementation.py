''' 
********** Code modified by - Aneri Sheth - 1401072************
**********This is an implemented algorithm for Neighborbood Component Analysis - NCA *************
''' 
import numpy as np 
import pylab as pl
import scipy.optimize as opt

#Cost function for NCA 
def costfunction(A, X, y, threshold=None):
    (D, N) = np.shape(X)
	#Matrix A defined
    A = np.reshape(A, (np.size(A) / np.size(X, axis=0), np.size(X, axis=0))) 
    (d, aux) = np.shape(A)
    assert D == aux
	AX = np.dot(A, X)
    normAX = np.linalg.norm(AX[:, :, None] - AX[:, None, :], axis=0)
	denomSum = np.sum(np.exp(-normAX[:, :]), axis=0)
	#Probaility assigned for each correctly identified classifier
    Pij = np.exp(- normAX) / denomSum[:, None]
	#Threshold condition for setting the classifier condition
    if threshold is not None:
        Pij[Pij < threshold] = 0
        Pij[Pij > 1-threshold] = 1
	mask = (y != y[:, None])
    Pijmask = np.ma.masked_array(Pij, mask)
    P = np.array(np.sum(Pijmask, axis=1))
    mask = np.negative(mask)
	f = np.sum(P)
	Xi = X[:, :, None] - X[:, None, :]
    Xi = np.swapaxes(Xi, 0, 2)
    Xi = Pij[:, :, None] * Xi
    Xij = Xi[:, :, :, None] * Xi[:, :, None, :]
	#Gradient function algorithm logic 
    gradfunction = np.sum(P[:, None, None] * np.sum(Xij[:], axis=1), axis=0)
	''' 
	For N samples, run a for loop, which computes the gradient for k test cases considering only 2 features 
	'''
    for i in range(N):
        aux = np.sum(Xij[i, mask[i]], axis=0)
        gradfunction -= aux
    gradfunction = 2 * np.dot(A, gradf)
    gradfunction = -np.reshape(gradfunction, np.size(gradfunction))
    f = np.size(X, 1) - f
    return [f, gradfunction]

#Function to maximize f(A) the maximum expected correctly identified classifiers
def f(A, X, y):
    return costfunction(A, X, y)[0]
#Computing the gradient ascent for the same set of classifiers
def grad(A, X, y):
    return costfunction(A, X, y)[1]

class NCA(object):
    #Objective is to compute Mahalanobis distance 
    def __init__(self, metric=None, dim=None,threshold=None, objective='Mahalanobis', **kwargs):
        self.metric = metric
        self.dim = dim
        self.threshold = threshold
        if objective == 'Mahalanobis':
            self.objective = cost
        self.kwargs = kwargs

    def fit(self, X, y):
        if self.metric is None:
            if self.dim is None:
                self.metric = np.eye(np.size(X, 1))
                self.dim = np.size(X, 1)
            else:
                self.metric = np.eye(self.dim, np.size(X, 1) - self.dim)

        res = opt.minimize(fun=self.objective,
                           x0=self.metric,
                           args=(X, y, self.threshold),
                           jac=True,
                           **self.kwargs
                           )

        self.metric = np.reshape(res.x,
                                 (np.size(res.x) / np.size(X, 0),
                                  np.size(X, 0)))
	#Linear Transformation on Input data 
    def fit_transform(self, X, y):
        self.fit(self, X, y)
        return np.dot(self.metric, X)

    def score(self, X, y):
        return 1 - costfunction(self.metric, X, y)[0]/np.size(X, 1)

    def getParameters(self):
        return dict(metric=self.metric, dim=self.dim, objective=self.objective,
                    threshold=self.threshold, **self.kwargs)

# Run the algorithm for 1000 samples 
N = 1000
aux = (np.concatenate([0.5*np.ones((N/2, 1)),
                       np.zeros((N/2, 1)), 1.1*np.ones((N/2, 1))], axis=1))
X = np.concatenate([np.random.rand(N/2, 3),
                    np.random.rand(N/2, 3) + aux])

y = np.concatenate([np.concatenate([np.ones((N/2, 1)), np.zeros((N/2, 1))]),
                    np.concatenate([np.zeros((N/2, 1)), np.ones((N/2, 1))])],
                   axis=1)
X = X.T
y = y[:, 0]
A = np.array([[1, 0, 0], [0, 1, 0]])

# Input data 
nca = NCA(metric=A, method='BFGS', objective='Mahalanobis', options={'maxiter': 10, 'disp': True})
print nca.score(X, y)
nca.fit(X, y)
print nca.score(X, y)

#Generate the graph 
pl.subplot(2, 1, 1)
AX = np.dot(A, X)
pl.scatter(AX[0, :], AX[1, :], 30, c=y)
pl.subplot(2, 1, 2)
BX = np.dot(np.reshape(nca.metric, np.shape(A)), X)
pl.scatter(BX[0, :], BX[1, :], 30, c=y)
pl.show()
