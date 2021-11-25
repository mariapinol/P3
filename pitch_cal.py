#! /usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import soundfile as sf

signal, fmuestreo=sf.read('sb050.wav')
time=np.arange(0,len(signal))/fmuestreo
plt.subplot(2,1,1)
plt.title('Señal temporal')
plt.plot(time,signal)

plt.subplot(2,1,2)
plt.title('Autocorrelación')
plt.acorr(signal, maxlags=500)

plt.show()

