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


class RadialHeatEquation:
    """This class contains the functionality to perform Crank Nickolson's method for 1D radial heat equation PDE.
    """
    def __init__(self, c_init: float, spatial_grid_pts: int) -> None:
        self.K: int = spatial_grid_pts
        self.c_init: np.ndarray = c_init * np.ones(self.K)
        self.c_prev: np.ndarray = self.c_init
        self.c_prev = self.c_prev.reshape(-1,1)

    def dr(self, R: float) -> float:
        """
        Difference in radial coordinate [m].
        :param R: electrode particle radius
        :return:
        """
        return R / self.K

    def A(self, dt: float, R: float, D: float) -> float:
        """
        Value of the constant A (delta_t * D / delta_r^2)
        :return: Returns the value of the A constant, used for the forming the matrices
        """
        return dt * D / (self.dr(R) ** 2)

    def B(self, dt: float, R: float, D: float) -> float:
        """
        Value of constant B (delta_t * D / (2 * delta_r))
        :return:
        """
        return dt * D / (2 * self.dr(R))
    
    def array_R(self, R: float) -> np.ndarray:
        """
        Array containing the values of r at every grid point.
        :return: Array containing the values of r at every grid point.
        """
        return np.linspace(0, R, self.K)
    
    def _LHS_diag_elements(self, dt: float, R: float, D: float) -> np.ndarray:
        A_ = self.A(dt=dt, R=R, D=D)
        array_elements = (1 + A_) * np.ones(self.K)
        array_elements[0] = 1 + 3 * A_  # for symmetry boundary condition at r=0
        array_elements[-1] = 1 + A_
        return array_elements

    def _LHS_lower_diag(self, dt: float, R: float, D: float) -> np.ndarray:
        A_ = self.A(dt=dt, R=R, D=D)
        B_ = self.B(dt=dt, R=R, D=D)
        array_elements = -(A_/2 - B_/self.array_R(R)[1:]) * np.ones(self.K-1)
        array_elements[-1] = -A_  # for the flux at r=R
        return array_elements

    def _LHS_upper_diag(self, dt: float, R: float, D: float) -> np.ndarray:
        A_ = self.A(dt=dt, R=R, D=D)
        B_ = self.B(dt=dt, R=R, D=D)
        array_elements = -(A_ / 2 + B_ / self.array_R(R)[1:-1]) * np.ones(self.K - 2)
        array_elements = np.insert(array_elements, 0, -3 * A_)  # for symmetry boundary condition at r=0
        return array_elements
    
    def M(self, dt: float, R: float, D: float) -> np.ndarray:
        return np.diag(self._LHS_diag_elements(dt=dt, R=R, D=D)) + \
               np.diag(self._LHS_lower_diag(dt=dt, R=R, D=D), -1) + \
               np.diag(self._LHS_upper_diag(dt=dt, R=R, D=D), 1)

    def _RHS_array(self, j: float, dt: float, R: float, D: float):
        A_ = self.A(dt=dt, R=R, D=D)
        B_ = self.B(dt=dt, R=R, D=D)
        array_c_temp = np.zeros(self.K).reshape(-1,1)
        array_c_temp[0][0] = (1-3*A_)*self.c_prev[0][0] + 3*A_*self.c_prev[1][0]  # for the symmetry boundary condition
        # at r=0
        array_c_temp[-1][0] = (1-A_) * self.c_prev[-1][0] - (A_+B_/R) * (2*self.dr(R=R)*j/D) + \
                              A_ * self.c_prev[-2][0]  # for the boundary condition at r=R
        for i in range(1, len(array_c_temp) - 1):
            array_c_temp[i][0] = (1 - A_) * self.c_prev[i][0] + \
                                 (A_ / 2 + B_ / self.array_R(R=R)[i]) * self.c_prev[i + 1][0] + \
                                 (A_ / 2 - B_ / self.array_R(R=R)[i]) * self.c_prev[i - 1][0]
        return array_c_temp
    
    def solve(self, dt: float, j: float, R: float, D: float):
        self.c_prev = np.linalg.inv(self.M(dt=dt, R=R, D=D)) @ self._RHS_array(j=j, dt=dt, R=R, D=D)
