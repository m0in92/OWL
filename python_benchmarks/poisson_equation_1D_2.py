"""
Contains the solution for the benchmark poisson equation for 1D. The example was obtained from:
    https://ammar-hakim.org/sj/je/je11/je11-fem-poisson.html
"""

from typing import Callable

import numpy as np
import matplotlib.pyplot as plt

from differential_equations import poisson_solve_1D


def func(x: float) -> float:
    return 1 - 2*(x**2)


def exact_solution(x: np.ndarray) -> np.ndarray:
    return x**2/2 - 2*x**4/12 + (2/12 - 1/2)*x


# solve
BC1: float = 0.0
BC2: float = 0.0
linesegment: np.ndarray = np.linspace(0, 1, 101)
result: np.ndarray = poisson_solve_1D(linesegment=linesegment, func=func, bc1=BC1, bc2=BC2)

print(result)

#plot
plt.plot(linesegment, result, label="numerical")
plt.plot(linesegment, exact_solution(linesegment), label="exact")

plt.legend()
plt.show()
