#include <iostream>
#include "SistemaJugadores.h"

int main() {                    // O(1)
    SistemaJugadores sistema;   // O(1)
    sistema.mostrarMenu();      // O(n log n) en el peor caso, dependiendo de las operaciones del usuario
    return 0;                   // O(1)
}
/*
Complejidad total del programa main:
Mejor caso: O(1) 
  - El usuario entra al menú y sale inmediatamente.

Caso promedio: O(n)
  - Equilibrio de operaciones de inserción, consulta y eliminación.

Peor caso: O(n log n)   
  - El usuario elige mostrar jugadores, operación dominada por el merge sort.
*/
