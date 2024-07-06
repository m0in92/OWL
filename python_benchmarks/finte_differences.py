import numpy as np

x: float = np.pi/4
df_exact: float = np.cos(x)

h: float = 0.1

print(df_exact)
print("centered finite difference: ", (np.sin(x+h) - np.sin(x-h))  / (2*h))

