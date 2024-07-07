from typing import Callable

import numpy as np
import matplotlib.pyplot as plt

from differential_equations import poisson_solve_1D


def func(x: float) -> float:
    return 1 - 2*(x**2)

# solve
BC1: float = 0.0
BC2: float = 1.0
linesegment: np.ndarray = np.linspace(0, 1, 101)
result: np.ndarray = poisson_solve_1D(linesegment=linesegment, func=func, bc1=BC1, bc2=BC2)

#plot
plt.plot(linesegment, result)
plt.show()
