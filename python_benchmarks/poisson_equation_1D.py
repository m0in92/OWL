from typing import Callable

import numpy as np
import matplotlib.pyplot as plt


def func(x: float) -> float:
    return 1 - 2*(x**2)


def poisson_solve(linesegment: np.ndarray, func: Callable, bc1: float, bc2: float) -> np.ndarray:
    SIZE: float = linesegment.shape[0]
    h: float = linesegment[1] - linesegment[0]

    lhs_matrix: np.ndarray = np.zeros([SIZE, SIZE])
    rhs_array: np.ndarray = np.zeros(SIZE)
    rhs_array[0] = bc1
    lhs_matrix[0][0] = 1
    for i in range(1, SIZE-1):
        lhs_matrix[i][i-1] = 1
        lhs_matrix[i][i] = -2
        lhs_matrix[i][i+1] = 1

        rhs_array[i] = func(linesegment[i])
    lhs_matrix[-1][-1] = 1
    rhs_array[-1] = bc2

    rhs_array = (h**2) * rhs_array

    return np.linalg.inv(lhs_matrix) @ rhs_array.reshape(-1,1)


# solve
BC1: float = 0.0
BC2: float = 1.0
linesegment: np.ndarray = np.linspace(0, 1, 101)
result: np.ndarray = poisson_solve(linesegment=linesegment, func=func, bc1=BC1, bc2=BC2)

print(result)

#plot
plt.plot(linesegment, result)
plt.show()
