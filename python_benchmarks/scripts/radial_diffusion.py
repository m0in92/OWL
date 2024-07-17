import time

import matplotlib.pyplot as plt

try:
    from python_benchmarks.differential_equations import RadialHeatEquation
except ModuleNotFoundError:
    import sys
    import pathlib

    PROJECT_DIR: str = pathlib.Path(__file__).parent.parent.parent.__str__()
    sys.path.append(PROJECT_DIR)
    from python_benchmarks.differential_equations import RadialHeatEquation



# simulation parameters
c_init: float = 1
D: float = 1e-3
dt: float = 1
j: float = -0.01
R: float = 1

solver_instance: RadialHeatEquation = RadialHeatEquation(c_init=c_init, spatial_grid_pts=100)

N_ITER: int = 1000

start_time: float = time.time()
for i in range(N_ITER):
    solver_instance.solve(dt=dt, j=j, R=R, D=D)
end_time: float = time.time()

print("Simulation Time (Python): ", end_time-start_time, " s")

# print results
print(solver_instance.c_prev)

# plots
plt.plot(solver_instance.c_init)
plt.plot(solver_instance.c_prev)

plt.show()
