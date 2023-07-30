# from `https://www.hello-statisticians.com/explain-terms-cat/matrix_factorization4.html#LU`

import numpy as np

def LU_decomposition(X):
    n = X.shape[0]
    L,U = np.zeros([n,n]), np.zeros([n,n])
    for i in range(n):
        for j in range(n):
            if i==0:
                if j==0:
                    L[i,j] = 1
                U[i,j] = X[i,j]
            elif j==0:
                L[i,j] = X[i,j]/U[0,0]
            elif i==j:
                L[i,j] = 1
                U[i,j] = X[i,j] - np.dot(L[i,:j],U[:i,j])
            elif i>j:
                L[i,j] = (X[i,j] - np.dot(L[i,:j],U[:j,j]))/U[j,j]
            elif j>i:
                U[i,j] = X[i,j] - np.dot(L[i,:i],U[:i,j])
    return L, U

A1 = np.array([[-6,-9,-2,7,-9],
              [42,59,7,53,56],
              [30,37,-8,-35,-33],
              [-42,-47,30,35,-33],
              [12,18,20,-64,43]])
L1, U1 = LU_decomposition(A1)

print(L1)
print(U1)
print(np.dot(L1,U1))