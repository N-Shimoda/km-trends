import numpy as np

P_inverse = np.array([[-1,1,-1],
                      [1,3,1],
                      [-1,1,3]])

P = np.array([[-2,1,-1],
              [1,1,0],
              [-1,0,1]])

A = np.array([[0,2,-2],
              [1,1,1],
              [-1,1,1]])

print(np.dot(P_inverse,A))