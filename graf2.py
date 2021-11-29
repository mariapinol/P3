import numpy as np
import matplotlib.pyplot as plt
import scipy.io.wavfile as wf

f0 = np.loadtxt("rl002.f0", dtype=float)
f0ref = np.loadtxt("rl002.f0ref", dtype=float)

fm = 20000
time = np.arange(0,len(f0)).astype(float)
time = time/fm

plt.subplot(211)
plt.title("Parámetros de la señal")
plt.plot(time, f0, linewidth =0.5)
plt.xlabel('Tiempo (s)')
plt.ylabel('pitch calculado (Hz)')
plt.grid(True)
plt.subplot(212)
plt.xlabel('Tiempo (s)')
plt.ylabel('pitch wavesurfer (Hz)')
plt.plot(time, f0ref, linewidth =0.5)
plt.grid(True)
plt.show()