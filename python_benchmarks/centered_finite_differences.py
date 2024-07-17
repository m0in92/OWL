import numpy as np
import matplotlib.pyplot as plt

Nx: int = 10

x: np.ndarray = np.linspace(0, 3.141592/2, 10)
y: np.ndarray = np.sin(x)
h: float = x[1] - x[0]

M: np.ndarray = np.zeros([10,10])
M_diag: np.ndarray = -2 * np.ones(Nx)
M_ldiag: np.ndarray = np.ones(Nx-1)
M_udiag: np.ndarray = np.ones(Nx-1)
M: np.ndarray = np.diag(M_diag) + np.diag(M_ldiag, -1) + np.diag(M_udiag, 1)

M = M / (h ** 2)
diff_result: np.ndarray = M @ y.reshape(-1,1)

# print results
print(diff_result.flatten())

# plots
plt.plot(x[1:-1], diff_result[1:-1])
plt.plot(x[1:-1], -np.sin(x[1:-1]))

plt.show()
