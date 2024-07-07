from typing import Callable

import numpy as np


def poisson_solve_1D(linesegment: np.ndarray, func: Callable, bc1: float, bc2: float) -> np.ndarray:
    """solves for 1D time-independent poisson equation using centered finite differences

    Args:
        linesegment (np.ndarray): array containing values for the 1D grid points.
        func (Callable): function representing the source term
        bc1 (float): value at the first boundary point
        bc2 (float): value at the second boundary point

    Returns:
        np.ndarray: array containing the solution
    """
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