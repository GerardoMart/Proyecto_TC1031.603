# Proyecto: Nombre de tu proyecto
Lo que se busca en este proyecto es poder gestionar a los jugadores del FC Barcelona en base a datos que los mismos poseen y modifican partido a partido.

## Descripción del avance 1
En mi primer avance, creé un programa el cuál me permite ordenar a los jugadores del Fútbol Club Barcelona provenientes de una lista cuyo formato es: nombre dorsal posicion edad goles, en base a varios parámetros, ya sea:
* Por nombre (en orden alfabético)
* Por cantidad de goles (de mayor a menor) 
* Por dorsal (de mayor a menor)
* Por posición (primero los porteros, luego defensas, después mediocampistas, y por úlitmo delanteros, exepciones de posición al final de la lista de este ordenamiento)
* Por edad (menor a mayor)

## Descripción del avance 2
En este, mi segundo avance, creé una estructura de datos la cuál me permita acceder de manera óptima y más rápida a mis datos que tengo guardados en el archivo "Lista.txt". Usé una lista doblemente ligada, aprovechando de esta manera para recorrer dicha lista de un sentido a otro dados sus nodos y apuntadores que los enlazan de forma doble. 

Dicha estructura de datos está implementada en el archivo "DList.h", y al implementarla, sustituimos los vectores que previamente usábamos en "main.cpp" y en "Sort.h", apareciendo ahora, como ejemplo: "DList< T >", "DLink< T >" y "DList< Jugador >" respectivamente.

### Cambios sobre el segundo avance
Agregué un nuevo archivo "SistemaJugadores.h" el cuál me ayuda con la creación de un menú interactivo y también para modificar y guardar cambios en mi archivo "Lista.txt" el cuál contiene los jugadores y sus respectivas estadísticas. 

También agregué setters en mi clase Jugador, el cuál ayuda a "SistemaJugadores.h" para cambiar los distintos atributos de los jugadores.

## Descripción del avance 3
En este tercer avance implementé un archivo nuevo "SistemasJugadores.h" para la gestión interactiva de jugadores del FC Barcelona, incorporando un menú principal el cuál incluye a su vez submenús organizados que te permiten navegar de forma intuitiva entre todas las funciones. 

El sistema ahora admite agregar, eliminar, modificar y buscar jugadores mediante diversos criterios, además de conservar los datos en memoria y actualizarlos en el archivo Lista.txt solo cuando el usuario lo confirma, garantizando la integridad de la información. 

Cabe aclarar que todo el sistema lo integré correctamente con la lista doblemente ligada y el algoritmo de ordenamiento desarrollados en avances anteriores, manteniendo y aprovechando de esta forma los criterios de ordenamiento ya establecidos previemente.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o tercerAvance`

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercerAvance` 

## Descripción de las entradas del avance de proyecto
El programa se compone por los archivos:

* Jugador.h define la estructura y comportamiento de un jugador del FC Barcelona, crea un criterio de ordenamiento para después seleccionar el deseado en el archivo main.cpp y convierte de posición a número para después ordenarlas.

* Sort.h primero crea una busqueda secuencial que recorre el vector v de izquierda a derecha.
Si encuentra el elemento objetivo, regresa su posición (el índice).
Si no lo encuentra, devuelve -1.

    También tiene un método llamado ´merge´ que fusiona dos subarreglos ya ordenados en un único subarreglo ordenado. Usa dos vectores temporales: I (izquierda) y D (derecha). Compara elemento por elemento con <= y los acomoda en el vector v para que la clase ´Jugador´ use el operador sobrecargado ´<=´ para que decida si un jugador va antes o después.

    El método ´mergeSort´ divide el vector en mitades recursivamente hasta llegar a subarreglos de tamaño 1 y luego los va fusionando (usando ´merge´) hasta reconstruir el vector ordenado.

    Por último, el método ´ordenaMerge´ es un atajo para que en el main sólo se tenga que llamar: ´s.ordenaMerge(jugadores);´ en lugar de escribir todo el mergeSort con índices manualmente.

* DList.h implementa una lista doblemente ligada (Double Linked List) que permite almacenar y manipular elementos conectados en ambas direcciones.
Es una estructura clave del proyecto, ya que facilita el manejo dinámico de datos de mis datos sin depender de un tamaño fijo de arreglo. 
*DLink* (Nodo doblemente encadenado) representa cada elemento de la lista y contiene tres partes:

    * value: almacena el dato genérico.

    * next: apunta al siguiente nodo.

    * prev: apunta al nodo anterior.

    Básicamente define cómo se enlazan los nodos hacia adelante y hacia atrás.

* List (Lista doblemente encadenada) es la clase principal y administra la lista completa a través de los apuntadores head (inicio) y tail (final). Incluye las operaciones esenciales:
   
    * insertion(T val) inserta un nuevo elemento al final de la lista. Si está vacía, el nuevo nodo se convierte en la cabeza y la cola.

    * search(T val) recorre la lista desde el inicio buscando un valor y devuelve su posición o -1 si no lo encuentra.

    * deleteAt(int pos) elimina el nodo en la posición indicada y ajusta los enlaces de los nodos vecinos.

    * toStringForward() devuelve el contenido de la lista como una cadena de texto, recorriéndola de principio a fin.



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

* SistemaJugadores.h es un sistema de gestión interactivo que proporciona una interfaz de usuario amigable para administrar los jugadores:

Sus funcionalidades principales son:

* Menú interactivo con navegación jerárquica.

* Gestión completa de jugadores (agregar, eliminar, modificar).

* Búsqueda avanzada por múltiples criterios (goles, dorsal, posición, edad).

* Persistencia de datos con guardado selectivo.

* Ordenamiento dinámico con todos los criterios disponibles.

Dentro de sus métodos clave se encuentran:

* cargarJugadores(): Carga datos desde archivo a la lista en memoria.

* guardarJugadores(): Guarda cambios persistentemente en el archivo.

* agregarJugador(), eliminarJugador(), modificarJugador(): Operaciones básicas de manejo de datos.

* mostrarJugadores(): Visualización con ordenamiento personalizable.

* buscarJugador(): Búsqueda por diferentes atributos.

* mostrarMenu(): Interfaz principal de usuario.

Y por último, main.cpp:
El cuál es un punto de entrada del programa que inicializa el sistema y ejecuta el menú principal.

## Descripción de las salidas del avance de proyecto
El programa ahora presenta un sistema interactivo completo que permite gestionar dinámicamente la plantilla de jugadores del FC Barcelona. Las salidas varían según las opciones seleccionadas en el menú:

1. Menú Principal Interactivo
Al ejecutar el programa, se muestra un menú navegable:

 Bienvenido/a al:

SISTEMA DE GESTIÓN DE JUGADORES FC BARCELONA

 Seleccione una opción:
1. Mostrar jugadores
2. Modificar jugadores
3. Encontrar jugador por...
4. Guardar cambios y salir

 Opción: [entrada del usuario]


2. Salidas al Mostrar Jugadores (Opción 1)
El usuario puede elegir entre 5 criterios de ordenamiento:


--- Mostrar Jugadores ---

Ordenar por:
1. Nombre (Orden alfabético)
2. Goles (mayor a menor)
3. Dorsal
4. Posición
5. Edad (Menor a mayor)

Opción: [entrada del usuario]
Ejemplo de salida ordenada por goles:


--- Lista de Jugadores ---

Nombre: Lewandowski, Numero: 9, Posicion: Delantero, Edad: 35, Goles: 45

Nombre: Pedri, Numero: 8, Posicion: Mediocampista, Edad: 21, Goles: 12

Nombre: Gavi, Numero: 6, Posicion: Mediocampista, Edad: 20, Goles: 10

Nombre: Araujo, Numero: 4, Posicion: Defensa, Edad: 26, Goles: 3

Nombre: TerStegen, Numero: 1, Posicion: Portero, Edad: 32, Goles: 0



3. Salidas del Submenú de Modificación (Opción 2)


--- Modificar Jugadores ---
1. Agregar jugador
2. Eliminar jugador
3. Modificar datos de un jugador
4. Volver al menú principal

Opción: [entrada del usuario]

Agregar Jugador:

--- Agregar Nuevo Jugador ---

Nombre: [entrada]

Dorsal: [entrada]

Posicion (Portero/Defensa/Mediocampista/Delantero): [entrada]

Edad: [entrada]

Goles (Que llevaría hasta ahora): [entrada]

Jugador agregado exitosamente! (Los cambios se verán modificados en el archivo Lista.txt una vez seleccione la opción 4 del menú principal...)

Eliminar Jugador:

--- Eliminar Jugador ---

Nombre del jugador a eliminar: [entrada]

Jugador eliminado: Nombre: TerStegen, Numero: 1, Posicion: Portero, Edad: 32, Goles: 0

Modificar Jugador:

--- Modificar Jugador ---

Nombre del jugador a modificar: [entrada]

Jugador encontrado. Datos actuales:

Nombre: Pedri, Numero: 8, Posicion: Mediocampista, Edad: 21, Goles: 12

¿Qué dato desea modificar?

1. Dorsal (actual: 8)
2. Posición (actual: Mediocampista)
3. Edad (actual: 21)
4. Goles (actual: 12)
5. Terminar modificación

Opción: [entrada]

[Proceso de modificación específico...]

4. Salidas de Búsqueda (Opción 3)

--- Buscar Jugador ---

Buscar por:

1. Número de goles
2. Número de dorsal
3. Posición
4. Edad

Opción: [entrada]

Ejemplo de búsqueda por posición:

Posición a buscar: Mediocampista

Jugadores en posición Mediocampista:

Nombre: Pedri, Numero: 8, Posicion: Mediocampista, Edad: 21, Goles: 12

Nombre: Gavi, Numero: 6, Posicion: Mediocampista, Edad: 20, Goles: 10

5. Salida Final (Opción 4)

Cambios guardados exitosamente!

Hasta luego!

6. Mensajes de Error y Validación

Jugador no encontrado: "Jugador no encontrado!"

Opción inválida: "Opción inválida!"

Lista vacía: "No hay jugadores en la lista."

Sin resultados de búsqueda: "No se encontraron jugadores con los criterios especificados."

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Considero que desarrollé esta competencia porque en el proyecto realicé un análisis explícito de la complejidad de los algoritmos implementados. En el archivo Sort.h documenté la complejidad de cada función usando la Notación asintótica o Big O notation, indicando si era O(1), O(n) o O(n log n), dependiendo de las operaciones y bucles que se ejecutan.

En particular, analicé el funcionamiento del Merge Sort, señalando que en el peor de los casos mantiene una complejidad de O(n log n) debido a la división recursiva del vector y el proceso de fusión de los subarreglos. También realicé un análisis de la complejidad de la búsqueda secuencial (O(n)), que aunque no es un algoritmo de ordenamiento, forma parte del mismo archivo para el funcionamiento del Merge Sort e inclusive realicé el análisis de complejidad de mi archivo Jugador.h, que fue muy sencillo de hecho.

Esto se puede observar directamente en el código donde, por cada método (busqSecuencial, merge, mergeSort, ordenaMerge), expliqué en comentarios su respectiva complejidad, además de aplicar dichos análisis al justificar el por qué Merge Sort era el más adecuado para ordenar una lista de jugadores que puede crecer en tamaño en la segunda competencia (SICT0302: Toma decisiones).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Cimplí con esta competencia en la parte correspondiente a las estructuras de datos, específicamente al implementar y documentar la lista doblemente ligada (DList). En este archivo, analicé y señalé explícitamente la complejidad temporal de cada operación básica, justificando su costo en función de las operaciones y ciclos que se ejecutan.

Por ejemplo, las operaciones insertion y empty tienen una complejidad O(1) ya que sólo manipulan punteros o variables simples, sin recorrer la lista. En cambio, métodos como search, update, deleteAt, y las funciones que generan una representación en cadena (toStringForward, toStringBackward) presentan una complejidad O(n), dado que recorren secuencialmente los nodos para completar su tarea.

Además, el destructor y el método clear también se analizaron, mostrando una complejidad O(n) por la liberación iterativa de memoria. Esto demuestra que hice un análisis completo tanto de las operaciones constantes como de las que dependen del tamaño de la lista, considerando los casos promedio y peor caso.

Este análisis se puede observar directamente en el código fuente (DList.h), donde cada función está documentada a manera de comentario con su complejidad individual. De esta forma, apliqué la notación que también usé en mi primer entrega, Big O Notation para justificar el rendimiento de la estructura y que es apto para operaciones de inserción y recorrido frecuentes dentro de mi lista (List.txt).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Considero que desarrollé correctamente esta competencia porque realicé un análisis ompleto de la complejidad de todos los componentes del sistema de gestión de jugadores. Puesto que extendí y unifiqué el análisis que se había hecho con anterioridad en mis entregas previas al resto del programa: en "Jugador.h" identifiqué que todas las operaciones son O(1), mientras que en "SistemaJugadores.h" clasifiqué los métodos según su comportamiento real (por ejemplo, cargar y guardar O(n), buscar y eliminar O(n), ordenar y mostrar O(n log n)). 

Con esto determiné la complejidad final del programa, que va desde O(1) en el mejor caso hasta O(n log n) en el peor, dependiendo de las acciones del usuario. Todo este análisis se evidencia directamente en el código mediante comentarios detallados, mostrando que cada decisión de diseño se tomó esperando que tenga un impacto eficiente en el desempeño global del sistema.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Desarrollé esta competencia porque elegí Merge Sort como algoritmo de ordenamiento principal en el proyecto. La decisión se tomó considerando que este algoritmo es eficiente para listas medianas o grandes y mantiene un rendimiento estable en el peor de los casos con O(n log n), a diferencia de otros como Bubble Sort o Insertion Sort que presentan una complejidad de O(n²).

El uso correcto del algoritmo se observa en la implementación de la clase ´Sort< T >', donde ordenaMerge simplifica la llamada al ordenamiento, permitiendo ordenar la lista de jugadores de acuerdo con distintos criterios que definí en la clase Jugador (nombre, goles, dorsal, posición o edad).

En el main.cpp, la correcta aplicación se aprecia cuando, tras leer el archivo "Lista.txt", se ordenan los jugadores múltiples veces cambiando únicamente el criterio de comparación mediante Jugador::setCriterio(). Esto demuestra que no sólo seleccioné el algorito de forma adecuada, sino que también lo integré correctamente con la sobrecarga de operadores en la clase Jugador, permitiendo versatilidad y reutilización del mismo algoritmo en diferentes contextos.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Considero que desarrollé esta competencia ya que seleccioné e implementé una lista doblemente ligada (DList) como estructura de datos principal para manejar la colección de jugadores cargada desde mi archivo "Lista.txt". Esta estructura resultó la más adecuada ya que me permite almacenar objetos complejos (como la clase Jugador) y recorrerlos en ambos sentidos, lo que facilita la aplicación de diferentes algoritmos de ordenamiento y la visualización personalizada de estos mismos datos.

A diferencia de un arreglo estático o un vector, como el que usé en mi entrega pasada, la lista doblemente ligada permite insertar y eliminar elementos sin necesidad de desplazar otros nodos (actualizando sólo los punteros), manteniendo un rendimiento que constante en las inserciones (O(1)). Esto me fue especialmente útil al leer los registros del archivo, ya que los jugadores se iban agregando dinámicamente conforme eran cargados del texto:

Pedri 8 Mediocampista 21 12  
Lewandowski 9 Delantero 35 45  
TerStegen 1 Portero 32 0  
Araujo 4 Defensa 26 5  
Gavi 6 Mediocampista 20 8

La estructura también me permitió recorrer los datos en ambos sentidos para generar salidas organizadas (por ejemplo, de la cabeza a la cola o al revés), y fue completamente compatible con el algoritmo de Merge Sort (Sort.h) implementado en la clase 'Sort< T >', que opera directamente sobre los punteros de mi lista de jugadores.

Lo justifico diciendo que fue una decisión fundamentada que equilibró la eficiencia, la claridad y flexibilidad, permitiéndome gestionar correctamente los objetos Jugador del archivo (en Jugador.h) y adaptarse a distintos criterios de ordenamiento y visualización dentro del programa.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
A mi parecer, desarrollé esta competencia pues implementé correctamente métodos de consulta dentro de la estructura DList, como search() y toStringForward()/toStringBackward(), que permiten acceder y visualizar la información almacenada de manera eficiente.

La función search() realiza una búsqueda lineal a lo largo de la lista, devolviendo la posición del elemento si existe o -1 si no se encuentra, lo cual, demuestra un mecanismo de consulta que es tanto controlado como seguro, evitando errores fuera de rango.

Además, los métodos toStringForward() y toStringBackward() me permiten recorrer la lista completa en ambos sentidos y mostrar de esta forma contenido como texto, lo que fue útil para verificar el correcto ordenamiento y la lectura de los jugadores. Estas funciones reflejan un uso adecuado de la estructura doblemente ligada, puesto que aprovechan sus punteros next y prev para navegar por los datos sin necesidad de índices.

Y bueno, el desarrollo de esta competencia se puede observar directamente en el archivo DList.h, donde cada método está implementado considerando la eficiencia y la claridad al consultar la información contenida en la lista que almacena a los jugadores.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Desarrollé esta competencia al implementar la lectura del archivo Lista.txt, en el cual se almacena la información de los jugadores con sus respectivos atributos que previamente aclaré: nombre, dorsal, posición, edad y goles.

En mi main.cpp, cada línea del archivo se procesa para así crear un objeto Jugador, que posteriormente se inserta en la lista doblemente ligada DList mediante el método insertion(). Este proceso me garantiza que todos los datos del archivo se carguen correctamente en memoria y se mantengan accesibles para las operaciones de búsqueda, actualización y ordenamiento.

Mi mecanismo de lectura también incluye validaciones, asegurando que los datos se asignen en el orden correcto a cada atributo de la clase Jugador. Gracias a esta estructura, los datos pueden ser reutilizados fácilmente para ordenarlos con Merge Sort, consultarlos o simplemente imprimirlos en pantalla.

Esta competencia se observa en el archivo principal del proyecto (main.cpp), donde se realiza la carga de datos desde Lista.txt hacia la estructura DList, demostrando el uso correcto de lectura de archivos y la integración fluida entre las clases del sistema.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Yo considero que desarrollé esta competencia ya que implementé un mecanismo el cuál permite una persistencia confiable mediante el método guardarJugadores() en la clase "SistemaJugadores", asegurando así que todos los datos almacenados en la lista doblemente enlazada se escriban correctamente en mi archivo "Lista.txt". 

Este proceso recorre la estructura DList desde el puntero head, volcando cada jugador en un formato uniforme y compatible con la lectura inicial, garantizando de esta forma la integridad y consistencia de los datos. Además, incorporé una validación al momento de abrir el archivo para evitar fallos en la escritura y permitir que el usuario decida de forma explícita cuándo guardar los cambios, evitando sobrescrituras accidentales. 

Este desarrollo puede observarse directamente en "SistemaJugadores.h", donde implementé el recorrido y la escritura secuencial, y en "main.cpp", donde el método se integra con la opción “Guardar cambios y salir”, demostrando una correcta conexión entre la estructura en memoria y el archivo persistente.