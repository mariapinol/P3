import matplotlib.pyplot as plt
import numpy as np
import soundfile as sf

signal, fmuestreo=sf.read('correlation_vocal_e.wav')
time=np.arange(0,len(signal))/fmuestreo
plt.subplot(2,1,1)
plt.title("Análisis de pitch")
plt.plot(time,signal)
plt.xlabel('Tiempo (s)')
plt.ylabel('Amplitud')
plt.grid(True)

plt.subplot(2,1,2)
plt.xlabel('Muestras')
plt.ylabel('Autocorrelación')
plt.acorr(signal, maxlags=500)
plt.grid(True)

plt.show() 