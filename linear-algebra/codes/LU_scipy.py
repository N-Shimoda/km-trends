# LU decomposition by scipy
 
import numpy as np
from scipy.linalg import lu

np.set_printoptions(precision=3)

# np.random.seed(7)
# A = np.random.randint(0, 10, (5, 5))

A = np.array([[-6,-9,-2,7,-9],
              [42,59,7,53,56],
              [30,37,-8,-35,-33],
              [-42,-47,30,35,-33],
              [12,18,20,-64,43]])

P, L, U = lu(A)

print("A:\n{}\n".format(A))
print("P:\n{}\n".format(P))
print("L:\n{}\n".format(L))
print("U:\n{}".format(U))