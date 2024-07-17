from typing import Callable

import numpy as np


def centered_finite_difference(func: Callable, array: np.ndarray, h: float) -> np.ndarray:
    result_array: np.ndarray = np.zeros(array.shape[0])
    for i in range(1, array.shape[0]-1):
        result_array[i] = (func(array[i+1]) - func(array[i-1])) / (2 * h)
    return result_array


x: float = np.linspace(0, np.pi/2, 10)
df_exact: float = np.cos(x)

h: float = x[1] - x[0]

print(df_exact)
print("centered finite difference: ", centered_finite_difference(func=np.sin, array=x, h=h))


