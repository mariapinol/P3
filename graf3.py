import numpy as np
import matplotlib.pyplot as plt
import scipy.io.wavfile as wf

f0 = np.loadtxt("rl002.f0", dtype=float)
f0_con= np.loadtxt("rl002_con.f0", dtype=float)
fm = 20000
time = np.arange(0,len(f0)).astype(float)
time = time/fm

plt.subplot(211)
plt.title("Comparación detección pitch sin y con técnicas de preprocesado y postprocesado")
plt.plot(time, f0, linewidth =0.5)
plt.xlabel('Tiempo (s)')
plt.ylabel('pitch calculado sin (Hz)')
plt.grid(True)
plt.subplot(212)
plt.xlabel('Tiempo (s)')
plt.ylabel('pitch calculado con (Hz)')
plt.plot(time, f0_con, linewidth =0.5)
plt.grid(True)
plt.show()