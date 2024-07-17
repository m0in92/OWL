import numpy as np
import matplotlib.pyplot as plt


def guassian(x):
    """Gaussian profile as initial condition."""
    return np.exp(-0.5*((x-1.0/2.0)**2)/0.05**2)


D: float = 0.01
dt: float = 0.00160256
C_A: float = 0.0
C_B: float = 0.0

A: float = 0.0
B:float = 1.0
SIZE: int = 100

x: np.ndarray = np.linspace(A, B, SIZE)
dx: float = x[1] - x[0]
print(dx)

# c0: np.ndarray = np.sin(np.pi * x).reshape(-1,1)
c0: np.ndarray = guassian(x=x).reshape(-1,1)

diag: np.ndarray = (1 - 2*D*dt/(dx**2)) * np.ones(SIZE)
diag[0] = 1
diag[-1] = 1
ldiag: np.ndarray = D*dt/(dx**2) * np.ones(SIZE-1)
ldiag[-1] = 0
udiag = ldiag
udiag[0] = 0

M: np.ndarray = np.diag(diag) + np.diag(ldiag, -1) + np.diag(udiag, 1)
c_prev: np.ndarray = c0
print(c0)

t_end: float = 1.0
n_t: int = int(t_end/dt)
for i in range(n_t):
    # print("iteration: ", i)
    c_prev[0][0] = C_A
    c_prev[-1][0] = C_B
    c = M @ c_prev
    c_prev = c
    # print(c)

# plots
# plt.plot(x, c0)
plt.plot(x, c)
plt.show()