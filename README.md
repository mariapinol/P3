PAV - P3: detección de pitch
============================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 3](https://github.com/albino-pav/P3).
Siga las instrucciones de la [Práctica 2](https://github.com/albino-pav/P2) para realizar un `fork` de la
misma y distribuir copias locales (*clones*) del mismo a los distintos integrantes del grupo de prácticas.

Recuerde realizar el *pull request* al repositorio original una vez completada la práctica.

Ejercicios básicos
------------------

- Complete el código de los ficheros necesarios para realizar la detección de pitch usando el programa
  `get_pitch`.

   * Complete el cálculo de la autocorrelación e inserte a continuación el código correspondiente.
   <img width="627" alt="Captura de pantalla 2021-11-25 a las 14 14 16" src="https://user-images.githubusercontent.com/92084115/143661057-a26bdafc-a6ab-4426-8a28-895f05ea8bbf.png">


   * Inserte una gŕafica donde, en un *subplot*, se vea con claridad la señal temporal de un segmento de
     unos 30 ms de un fonema sonoro y su periodo de pitch; y, en otro *subplot*, se vea con claridad la
	 autocorrelación de la señal y la posición del primer máximo secundario.
	 
	 NOTA: es más que probable que tenga que usar Python, Octave/MATLAB u otro programa semejante para
	 hacerlo. Se valorará la utilización de la librería matplotlib de Python.
	 

El código que hemos hecho para la generación de la gráfica se encuentra en el fichero graf1.py.

![Figure_1_bona](https://user-images.githubusercontent.com/92084115/143661289-e6360bb4-9e4f-4920-acf2-33a00b67e640.png)

 El segmento de audio que hemos grabado contiene la vocal "e". Se puede escuchar el audio abriendo el fichero "correlation_vocal_e.wav". Cuando hacemos el cálculo, obtenemos una autocorrelación par respecto al origen. Para su representación, con la ayuda de la biblioteca matplotlib de Python, hemos usado el siguiente código:

	 
<img width="538" alt="Captura de pantalla 2021-11-27 a las 0 49 01" src="https://user-images.githubusercontent.com/92084115/143661508-c9ad8fc2-9f67-43c3-aaf1-e64bea0e54af.png">


   * Determine el mejor candidato para el periodo de pitch localizando el primer máximo secundario de la
     autocorrelación. Inserte a continuación el código correspondiente.
<img width="536" alt="Captura de pantalla 2021-11-27 a las 0 34 35" src="https://user-images.githubusercontent.com/92084115/143661127-6869edf9-c601-4eda-abc7-022fc7a81d0d.png">


   * Implemente la regla de decisión sonoro o sordo e inserte el código correspondiente.
<img width="851" alt="Captura de pantalla 2021-11-27 a las 0 39 56" src="https://user-images.githubusercontent.com/92084115/143661265-9490f0e5-7935-490c-a19c-d13cd7a2a00c.png">


- Una vez completados los puntos anteriores, dispondrá de una primera versión del detector de pitch. El 
  resto del trabajo consiste, básicamente, en obtener las mejores prestaciones posibles con él.

  * Utilice el programa `wavesurfer` para analizar las condiciones apropiadas para determinar si un
    segmento es sonoro o sordo. 
	
	  - Inserte una gráfica con la detección de pitch incorporada a `wavesurfer` y, junto a ella, los 
	    principales candidatos para determinar la sonoridad de la voz: el nivel de potencia de la señal
		(r[0]), la autocorrelación normalizada de uno (r1norm = r[1] / r[0]) y el valor de la
		autocorrelación en su máximo secundario (rmaxnorm = r[lag] / r[0]).
		
		
	    Puede considerar, también, la conveniencia de usar la tasa de cruces por cero.

	    Recuerde configurar los paneles de datos para que el desplazamiento de ventana sea el adecuado, que
		en esta práctica es de 15 ms.
		
<img width="1440" alt="Captura de pantalla 2021-11-29 a las 16 44 31" src="https://user-images.githubusercontent.com/92084115/143898549-8a82f3b1-be45-4f3e-b1f6-f833b5f8c7dc.png">

En la imagen anterior podemos ver diferentes gráficas que correspoden al nivel de potencia, a la correlación noramalizada, al valor de la autocorrelación en su máximo secundario de nuestra señal sonora (vocal e) y la detección del pich que hace el wavesurfer, es decir, la primera es rmaxnorm, la segunda es r1rom, la tercera es pot(r[0]) y la cuarta es la detcción del pitch directamenre desde el wavesurfer. Con estas graficas se puede ver como se decetacta correctamente la sonoridad de la voz.

<img width="1439" alt="Captura de pantalla 2021-11-29 a las 16 31 35" src="https://user-images.githubusercontent.com/92084115/143896349-7bdf3a92-3665-4dfc-a13e-4e303e235d4b.png">

Ahora para acabar de analizar la detcción del pitch, en la imagen anterior podemos ver el detector de pitch implementado con nuestro código (formato data plot), el pitch que detecta el wavesurfer y la señal de voz sonora. Se observa que nuestra detección es bastante correcta aunque podria mejorarse.


      - Use el detector de pitch implementado en el programa `wavesurfer` en una señal de prueba y compare
	    su resultado con el obtenido por la mejor versión de su propio sistema.  Inserte una gráfica
		ilustrativa del resultado de ambos detectores.
		
<img width="1440" alt="Captura de pantalla 2021-11-26 a las 22 56 30" src="https://user-images.githubusercontent.com/92084115/143657670-3033e494-ea58-460d-b37d-c153fcffe46c.png">

  
  * Optimice los parámetros de su sistema de detección de pitch e inserte una tabla con las tasas de error
    y el *score* TOTAL proporcionados por `pitch_evaluate` en la evaluación de la base de datos 
	`pitch_db/train`..
	Los valores de los umbrales que funcionan mejor para la detección de las tramas sordas son:

Sin ningún preprocesado ni postprocedado, nuestro sistema de detección de pitch tiene una puntuación de 92.60%: 

![image](https://user-images.githubusercontent.com/92084115/143894037-ada03954-0b03-4b23-a9a0-b3e7d1c33c44.png)

En las imagenes ateriores, la primera imagen corresponde al pitch optimizado implementado con nuestro código (formato pitch contour) y la segunda al pitch que detecta el wavesurfer. El pitch calculado y el proporcionado por el wavesurfer son muy parecidos, por lo que estamos satisfechas con el resultado obtenido, aunque siempre se podría mejorar aún más.

Para tener una mejor detección de los segmentos de audio de la base de datos, hemos modificado parámetros en el detector de sonoridad.
El valor que sale en pantalla creemos que es adecuado ya que está por encima del 90%, en concreto, 92.60%

   * Inserte una gráfica en la que se vea con claridad el resultado de su detector de pitch junto al del
     detector de Wavesurfer. Aunque puede usarse Wavesurfer para obtener la representación, se valorará
	 el uso de alternativas de mayor calidad (particularmente Python).

<img width="1440" alt="Captura de pantalla 2021-11-29 a las 17 23 58" src="https://user-images.githubusercontent.com/92084115/143904964-5ce07147-bc41-46d0-b48d-5cc5df4588d0.png">


<img width="536" alt="Captura de pantalla 2021-11-29 a las 17 30 19" src="https://user-images.githubusercontent.com/92084115/143905949-ba6c21a8-0450-401d-a3df-0bd0d1f3a91c.png">

Para realizar este apartado hemos usado Python. En primer lugar, vemos el pitch optimizado que hemos implementado con nuestro código (gráfica de arriba) y, en segundo lugar, el pitch que detecta el wavesurfer (gráfica de abajo). El pitch calculado y el proporcionado por el wavesurfer son prácticamente iguales, por lo que estamos satisfechas con el resultado obtenido.


   
Ejercicios de ampliación
------------------------

- Usando la librería `docopt_cpp`, modifique el fichero `get_pitch.cpp` para incorporar los parámetros del
  detector a los argumentos de la línea de comandos.
  
  Esta técnica le resultará especialmente útil para optimizar los parámetros del detector. Recuerde que
  una parte importante de la evaluación recaerá en el resultado obtenido en la detección de pitch en la
  base de datos.

  * Inserte un *pantallazo* en el que se vea el mensaje de ayuda del programa y un ejemplo de utilización
    con los argumentos añadidos.
    
 <img width="571" alt="Captura de pantalla 2021-11-27 a las 0 43 09" src="https://user-images.githubusercontent.com/92084115/143661363-1a85ce06-4c13-42d4-9747-4d51e6195f2e.png">
 
 En la imagen anterior se inserta el mensaje de ayuda del programa.
 
 Un ejemplo de uso podría ser el siguiente:
 
<img width="421" alt="Captura de pantalla 2021-11-30 a las 13 32 24" src="https://user-images.githubusercontent.com/92084115/144047918-0d2d480f-2ba7-4a22-b128-0961c27b890d.png">


 El 51 es el threshold (umbral) de potencia, seguido de los thresholds de r1norm y rmaxnorm.
 Poniendo estos valores en los diferentes umbrales obtenemos este resultado.
 
<img width="378" alt="Captura de pantalla 2021-11-30 a las 13 31 38" src="https://user-images.githubusercontent.com/92084115/144047868-f7a7bd5a-d1ba-4746-9552-d2cd570d5d6a.png">


 En el caso de que no modifiquemos los umbrales, estos por defecto los tenemos a 51.5 (th potencia), 0.6 (th r1norm) y 0.25 (th rmaxnorm). 


- Implemente las técnicas que considere oportunas para optimizar las prestaciones del sistema de detección
  de pitch.

  Entre las posibles mejoras, puede escoger una o más de las siguientes:

  * Técnicas de preprocesado: filtrado paso bajo, *center clipping*, etc.
  * Técnicas de postprocesado: filtro de mediana, *dynamic time warping*, etc.
  * Métodos alternativos a la autocorrelación: procesado cepstral, *average magnitude difference function*
    (AMDF), etc.
  * Optimización **demostrable** de los parámetros que gobiernan el detector, en concreto, de los que
    gobiernan la decisión sonoro/sordo.
  * Cualquier otra técnica que se le pueda ocurrir o encuentre en la literatura.

  Encontrará más información acerca de estas técnicas en las [Transparencias del Curso](https://atenea.upc.edu/pluginfile.php/2908770/mod_resource/content/3/2b_PS%20Techniques.pdf)
  y en [Spoken Language Processing](https://discovery.upc.edu/iii/encore/record/C__Rb1233593?lang=cat).
  También encontrará más información en los anexos del enunciado de esta práctica.

  Incluya, a continuación, una explicación de las técnicas incorporadas al detector. Se valorará la
  inclusión de gráficas, tablas, código o cualquier otra cosa que ayude a comprender el trabajo realizado.
  
Se ha implementado center clipping:

<img width="532" alt="Captura de pantalla 2021-11-30 a las 12 23 03" src="https://user-images.githubusercontent.com/92084115/144038753-2d048343-26a4-4e4e-bfe4-5812f76bcd0b.png">



Se ha implementado una version del filtro de mediana:

<img width="391" alt="Captura de pantalla 2021-11-30 a las 12 49 38" src="https://user-images.githubusercontent.com/92084115/144042247-3d6c3236-945d-49b0-b145-cc38092c92d4.png">

El resultado a mejorada muy poco por algun motivo que desconocemos, igualmente hemos pensado en adjuntar en este apartado la detección del pitch antes del center clipping y el filtro de mediana y la detección del pitch después de aplicar estas técnicas: 

<img width="1291" alt="Captura de pantalla 2021-11-30 a las 14 18 04" src="https://user-images.githubusercontent.com/92084115/144054475-885d4058-3cdf-48d0-a2be-acc14245298a.png">

El código que hemos hecho para la generación de las gráficas es el siguiente y se encuentra en el fichero graf3.py.

<img width="724" alt="Captura de pantalla 2021-11-30 a las 14 18 39" src="https://user-images.githubusercontent.com/92084115/144054533-bb032ed3-ea44-4f82-8408-3f3f013ae790.png">


  También se valorará la realización de un estudio de los parámetros involucrados. Por ejemplo, si se opta
  por implementar el filtro de mediana, se valorará el análisis de los resultados obtenidos en función de
  la longitud del filtro.
 

   

Evaluación *ciega* del detector
-------------------------------

Antes de realizar el *pull request* debe asegurarse de que su repositorio contiene los ficheros necesarios
para compilar los programas correctamente ejecutando `make release`.

Con los ejecutables construidos de esta manera, los profesores de la asignatura procederán a evaluar el
detector con la parte de test de la base de datos (desconocida para los alumnos). Una parte importante de
la nota de la práctica recaerá en el resultado de esta evaluación.
