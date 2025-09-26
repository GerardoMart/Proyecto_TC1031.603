# Proyecto: FC Barcelona Management
Lo que se busca en este proyecto es poder gestionar a los jugadores del FC Barcelona en base a datos que los mismos poseen y modifican partido a partido.

## Descripción del avance 1
En este primer avance, creé un programa el cuál me permite ordenar a los jugadores del Fútbol Club Barcelona provenientes de una lista cuyo formato es: nombre dorsal posicion edad goles, en base a varios parámetros, ya sea:
* Por nombre (en orden alfabético)
* Por cantidad de goles (de mayor a menor) 
* Por dorsal (de mayor a menor)
* Por posición (primero los porteros, luego defensas, después mediocampistas, y por úlitmo delanteros, exepciones de posición al final de la lista de este ordenamiento)
* Por edad (menor a mayor)

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal (una vez descargados los archivos Jugador.h, Sort.h, Lista.txt y main.cpp):

`g++ main.cpp -o primerAvance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primerAvance` 

## Descripción de las entradas del avance de proyecto
El programa se compone por los archivos:

* Jugador.h define la estructura y comportamiento de un jugador del FC Barcelona, crea un criterio de ordenamiento para después seleccionar el deseado en el archivo main.cpp y convierte de posición a número para después ordenarlas.

* Sort.h primero crea una busqueda secuencial que recorre el vector v de izquierda a derecha.
Si encuentra el elemento objetivo, regresa su posición (el índice).
Si no lo encuentra, devuelve -1.

    También tiene un método llamado ´merge´ que fusiona dos subarreglos ya ordenados en un único subarreglo ordenado. Usa dos vectores temporales: I (izquierda) y D (derecha). Compara elemento por elemento con <= y los acomoda en el vector v para que la clase ´Jugador´ use el operador sobrecargado ´<=´ para que decida si un jugador va antes o después.

    El método ´mergeSort´ divide el vector en mitades recursivamente hasta llegar a subarreglos de tamaño 1 y luego los va fusionando (usando ´merge´) hasta reconstruir el vector ordenado.

    Por último, el método ´ordenaMerge´ es un atajo para que en el main sólo se tenga que llamar: ´s.ordenaMerge(jugadores);´ en lugar de escribir todo el mergeSort con índices manualmente.

* Lista.txt, un archivo de texto plano el cual contiene la información de algunos jugadores del FC Barcelona.

Cada línea del archivo representa a un jugador con el siguiente formato:

Nombre Numero Posicion Edad Goles


* Nombre: una cadena de texto (sin espacios).

* Número (dorsal): un número entero.

* Posición: una cadena de texto (Portero, Defensa, Mediocampista o Delantero).

* Edad: un número entero.

* Goles: un número entero.

Ejemplo de datos que vienen en el archivo ´Lista.txt´:
* Pedri 8 Mediocampista 21 12
* Lewandowski 9 Delantero 35 45
* TerStegen 1 Portero 32 0
* Araujo 4 Defensa 26 3
* Gavi 6 Mediocampista 20 10

## Descripción de las salidas del avance de proyecto
El programa despliega en consola distintas versiones de la lista de los jugadores, ordenadas mediante el algoritmo Merge Sort de acuerdo con diferentes criterios:

* Lista original: tal como aparece en el archivo Lista.txt.

* Ordenados por nombre (alfabéticamente).

* Ordenados por goles (de mayor a menor).

* Ordenados por número de dorsal (menor a mayor).

* Ordenados por posición en el siguiente orden: Portero → Defensa → Mediocampista → Delantero.

* Ordenados por edad (menor a mayor).

Cada jugador se muestra en el siguiente formato:

* Nombre: nombre, Numero: dorsal, Posicion: posición, Edad: edad, Goles: goles anotados.

Ejemplos de salida:

* Lista original:

    Nombre: Pedri, Numero: 8, Posicion: Mediocampista, Edad: 21, Goles: 12

    Nombre: Lewandowski, Numero: 9, Posicion: Delantero, Edad: 35, Goles: 45

    Nombre: TerStegen, Numero: 1, Posicion: Portero, Edad: 32, Goles: 0

    Nombre: Araujo, Numero: 4, Posicion: Defensa, Edad: 26, Goles: 3

    Nombre: Gavi, Numero: 6, Posicion: Mediocampista, Edad: 20, Goles: 10

* Ordenados por goles (Mayor a menor):

    Nombre: Lewandowski, Numero: 9, Posicion: Delantero, Edad: 35, Goles: 45

    Nombre: Pedri, Numero: 8, Posicion: Mediocampista, Edad: 21, Goles: 12

    Nombre: Gavi, Numero: 6, Posicion: Mediocampista, Edad: 20, Goles: 10

    Nombre: Araujo, Numero: 4, Posicion: Defensa, Edad: 26, Goles: 3

    Nombre: TerStegen, Numero: 1, Posicion: Portero, Edad: 32, Goles: 0


## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Considero que desarrollé esta competencia porque en el proyecto realicé un análisis explícito de la complejidad de los algoritmos implementados. En el archivo Sort.h documenté la complejidad de cada función usando la Notación asintótica o Big O notation, indicando si era O(1), O(n) o O(n log n), dependiendo de las operaciones y bucles que se ejecutan.

En particular, analicé el funcionamiento del Merge Sort, señalando que en el peor de los casos mantiene una complejidad de O(n log n) debido a la división recursiva del vector y el proceso de fusión de los subarreglos. También realicé un análisis de la complejidad de la búsqueda secuencial (O(n)), que aunque no es un algoritmo de ordenamiento, forma parte del mismo archivo para el funcionamiento del Merge Sort e inclusive realicé el análisis de complejidad de mi archivo Jugador.h, que fue muy sencillo de hecho.

Esto se puede observar directamente en el código donde, por cada método (busqSecuencial, merge, mergeSort, ordenaMerge), expliqué en comentarios su respectiva complejidad, además de aplicar dichos análisis al justificar el por qué Merge Sort era el más adecuado para ordenar una lista de jugadores que puede crecer en tamaño en la segunda competencia (SICT0302: Toma decisiones).

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Desarrollé esta competencia porque elegí Merge Sort como algoritmo de ordenamiento principal en el proyecto. La decisión se tomó considerando que este algoritmo es eficiente para listas medianas o grandes y mantiene un rendimiento estable en el peor de los casos con O(n log n), a diferencia de otros como Bubble Sort o Insertion Sort que presentan una complejidad de O(n²).

El uso correcto del algoritmo se observa en la implementación de la clase ´Sort< T >', donde ordenaMerge simplifica la llamada al ordenamiento, permitiendo ordenar la lista de jugadores de acuerdo con distintos criterios que definí en la clase Jugador (nombre, goles, dorsal, posición o edad).

En el main.cpp, la correcta aplicación se aprecia cuando, tras leer el archivo Lista.txt, se ordenan los jugadores múltiples veces cambiando únicamente el criterio de comparación mediante Jugador::setCriterio(). Esto demuestra que no sólo seleccioné el algorito de forma adecuada, sino que también lo integré correctamente con la sobrecarga de operadores en la clase Jugador, permitiendo versatilidad y reutilización del mismo algoritmo en diferentes contextos.
