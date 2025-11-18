#ifndef SISTEMA_JUGADORES_H
#define SISTEMA_JUGADORES_H

#include "Jugador.h"
#include "DList.h"
#include "Sort.h"
#include <fstream>
#include <string>
#include <iostream>
#include <limits>

class SistemaJugadores {
private:
    DList<Jugador> jugadores;   // O(1) - espacio
    string archivoNombre;       // O(1) - espacio

public:
    SistemaJugadores(string filename = "Lista.txt") : archivoNombre(filename) {
        cargarJugadores();  // O(n) donde n = número de jugadores
        // Complejidad total: O(n)
    }

    void cargarJugadores() {
        ifstream archivo(archivoNombre);                                       // O(1)
        if (!archivo) {                                                        // O(1)
            cout << "No se pudo abrir el archivo: " << archivoNombre << endl;  // O(1)
            return;                                                            // O(1)
        }

        string nombre, posicion;          // O(1)
        int dorsal, edad, goles;          // O(1)

        while (archivo >> nombre >> dorsal >> posicion >> edad >> goles) {        // O(n)
            jugadores.insertion(Jugador(nombre, dorsal, posicion, edad, goles));  // O(1) por inserción
        }
        archivo.close();                                                          // O(1)
        // Complejidad total: O(n)
    }

    void guardarJugadores() {
        ofstream archivo(archivoNombre);                     // O(1)
        if (!archivo) {                                      // O(1)  
            cout << "Error al guardar el archivo!" << endl;  // O(1)
            return;                                          // O(1)
        }

        DLink<Jugador>* actual = jugadores.getHead();       // O(1)
        while (actual != nullptr) {                         // O(n)
            archivo << actual->value.getNombre() << " "     // O(1)
                   << actual->value.getNumero() << " "      // O(1)
                   << actual->value.getPosicion() << " "    // O(1)
                   << actual->value.getEdad() << " "        // O(1)
                   << actual->value.getGoles() << endl;     // O(1)
            actual = actual->next;                          // O(1)
        }
        archivo.close();                                    // O(1)
        cout << "Cambios guardados exitosamente!" << endl;  // O(1)
        // Complejidad total: O(n)
    }

    void limpiarBuffer() {
        cin.clear();                                           // O(1)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // O(1)
        // Complejidad total: O(1)
    }

    void agregarJugador() {
        string nombre, posicion;  // O(1)
        int dorsal, edad, goles;  // O(1)

        cout << "\n--- Agregar Nuevo Jugador ---" << endl;  // O(1)
        
        cout << "Nombre: ";                     // O(1)
        limpiarBuffer();                        // O(1)
        getline(cin, nombre);                   // O(1)
        
        cout << "Dorsal: ";                     // O(1)
        cin >> dorsal;                          // O(1)
        
        cout << "Posicion (Portero/Defensa/Mediocampista/Delantero): ";  // O(1)
        limpiarBuffer();                        // O(1)
        getline(cin, posicion);                 // O(1)
        
        cout << "Edad: ";                       // O(1)
        cin >> edad;                            // O(1)
        
        cout << "Goles (Que llevaría hasta ahora): ";  // O(1)
        cin >> goles;                           // O(1)

        jugadores.insertion(Jugador(nombre, dorsal, posicion, edad, goles));                                // O(1)
        cout << "Jugador agregado exitosamente! (Los cambios se verán modificados en el archivo Lista.txt"  // O(1)
             << " una vez seleccione la opción 4 del menú principal: Guardar cambios y salir.)" << endl;    // O(1)
        // Complejidad total: O(1)
    }

    void eliminarJugador() {
        string nombre;                                 // O(1)
        cout << "\n--- Eliminar Jugador ---" << endl;  // O(1)
        cout << "Nombre del jugador a eliminar: ";     // O(1)
        limpiarBuffer();                               // O(1)
        getline(cin, nombre);                          // O(1)

        DLink<Jugador>* actual = jugadores.getHead();  // O(1)
        int posicion = 0;                              // O(1)
        bool encontrado = false;                       // O(1)

        while (actual != nullptr) {                     // O(n) - búsqueda lineal
            if (actual->value.getNombre() == nombre) {  // O(1)
                encontrado = true;                      // O(1)
                break;                                  // O(1)
            }
            actual = actual->next;                      // O(1)
            posicion++;                                 // O(1)
        }

        if (encontrado) {
            try {
                Jugador eliminado = jugadores.deleteAt(posicion);  // O(n)
                cout << "Jugador eliminado: ";                     // O(1)
                eliminado.mostrar();                               // O(1)
            } catch (const std::out_of_range& e) {                 // O(1)
                cout << "Error al eliminar: " << e.what() << endl; // O(1)
            }
        } else {
            cout << "Jugador no encontrado!" << endl;              // O(1)
        }
        // Complejidad total: O(n)
    }

    void modificarJugador() {
        string nombre;                                  // O(1)
        cout << "\n--- Modificar Jugador ---" << endl;  // O(1)
        cout << "Nombre del jugador a modificar: ";     // O(1)
        limpiarBuffer();                                // O(1)
        getline(cin, nombre);                           // O(1)

        DLink<Jugador>* actual = jugadores.getHead();  // O(1)
        bool encontrado = false;                       // O(1)
        int posicion = 0;                              // O(1)

        while (actual != nullptr) {                     // O(n)
            if (actual->value.getNombre() == nombre) {  // O(1)
                encontrado = true;                      // O(1)
                break;                                  // O(1)
            }
            actual = actual->next;                      // O(1)
            posicion++;                                 // O(1)
        }

        if (!encontrado) {
            cout << "Jugador no encontrado!" << endl;   // O(1)
            return;                                     // O(1)
        }

        cout << "\nJugador encontrado. Datos actuales:" << endl;  // O(1)
        actual->value.mostrar();                                  // O(1)

        int opcion;                                                                        // O(1)
        do {
            cout << "\n¿Qué dato desea modificar?" << endl;                                // O(1)
            cout << "1. Dorsal (actual: " << actual->value.getNumero() << ")" << endl;     // O(1)
            cout << "2. Posición (actual: " << actual->value.getPosicion() << ")" << endl; // O(1)
            cout << "3. Edad (actual: " << actual->value.getEdad() << ")" << endl;         // O(1)
            cout << "4. Goles (actual: " << actual->value.getGoles() << ")" << endl;       // O(1)
            cout << "5. Terminar modificación" << endl;                                    // O(1)
            cout << "\nOpción: ";                                                          // O(1)
            cin >> opcion;                                                                 // O(1)

            switch (opcion) {
                case 1: {
                    int nuevoDorsal;                         // O(1)
                    cout << "Nuevo dorsal: ";                // O(1)
                    cin >> nuevoDorsal;                      // O(1)
                    Jugador modificado = actual->value;      // O(1)
                    modificado.setNumero(nuevoDorsal);       // O(1)
                    jugadores.update(posicion, modificado);  // O(n)
                    cout << "Dorsal actualizado!" << endl;   // O(1)
                    break;
                }
                case 2: {
                    string nuevaPosicion;                      // O(1)
                    cout << "Nueva posición: ";                // O(1)
                    limpiarBuffer();                           // O(1)
                    getline(cin, nuevaPosicion);               // O(1)
                    Jugador modificado = actual->value;        // O(1)
                    modificado.setPosicion(nuevaPosicion);     // O(1)
                    jugadores.update(posicion, modificado);    // O(n)
                    cout << "Posición actualizada!" << endl;   // O(1)
                    break;
                }
                case 3: {
                    int nuevaEdad;                           // O(1)
                    cout << "Nueva edad: ";                  // O(1)
                    cin >> nuevaEdad;                        // O(1)
                    Jugador modificado = actual->value;      // O(1)
                    modificado.setEdad(nuevaEdad);           // O(1)
                    jugadores.update(posicion, modificado);  // O(n)
                    cout << "Edad actualizada!" << endl;     // O(1)
                    break;
                }
                case 4: {
                    int nuevosGoles;                         // O(1)
                    cout << "Nuevos goles: ";                // O(1)
                    cin >> nuevosGoles;                      // O(1)
                    Jugador modificado = actual->value;      // O(1)
                    modificado.setGoles(nuevosGoles);        // O(1)
                    jugadores.update(posicion, modificado);  // O(n)
                    cout << "Goles actualizados!" << endl;   // O(1)
                    break;
                }
                case 5:
                    cout << "Modificación terminada." << endl;// O(1)
                    break;
                default:
                    cout << "Opción inválida!" << endl;       // O(1)
                    limpiarBuffer();                          // O(1)
            }
        } while (opcion != 5);                    // O(k) donde k = número de modificaciones (constante)
        // Complejidad total: O(n)
    }

    void mostrarJugadores() {
        if (jugadores.empty()) {                   // O(1)
            cout << "No hay jugadores en la lista." << endl;  // O(1)
            return;                               // O(1)
        }

        int criterio;                             // O(1)
        cout << "\n--- Mostrar Jugadores ---" << endl;  // O(1)
        cout << "Ordenar por:" << endl;           // O(1)
        cout << "1. Nombre (Orden alfabético)" << endl;    // O(1)
        cout << "2. Goles (mayor a menor)" << endl;        // O(1)
        cout << "3. Dorsal" << endl;              // O(1)
        cout << "4. Posición" << endl;            // O(1)
        cout << "5. Edad (Menor a mayor)" << endl;// O(1)
        cout << "\nOpción: ";                     // O(1)
        cin >> criterio;                          // O(1)

        if (criterio < 1 || criterio > 5) {       // O(1)
            cout << "Opción inválida!" << endl;   // O(1)
            return;                               // O(1)
        }

        Jugador::setCriterio(criterio - 1);       // O(1)
        Sort<Jugador> s;                          // O(1)
        s.ordenaMerge(jugadores);                 // O(n log n)

        cout << "\n--- Lista de Jugadores ---" << endl;  // O(1)
        DLink<Jugador>* actual = jugadores.getHead();  // O(1)
        while (actual != nullptr) {              // O(n)
            actual->value.mostrar();             // O(1)
            actual = actual->next;               // O(1)
        }
        // Complejidad total: O(n log n)
    }

    void buscarJugador() {
        int opcion;                              // O(1)
        cout << "\n--- Buscar Jugador ---" << endl;  // O(1)
        cout << "Buscar por:" << endl;           // O(1)
        cout << "1. Número de goles" << endl;    // O(1)
        cout << "2. Número de dorsal" << endl;   // O(1)
        cout << "3. Posición" << endl;           // O(1)
        cout << "4. Edad" << endl;               // O(1)
        cout << "\nOpción: ";                    // O(1)
        cin >> opcion;                           // O(1)

        DLink<Jugador>* actual = jugadores.getHead();  // O(1)
        bool encontrado = false;                 // O(1)

        switch (opcion) {
            case 1: {
                int goles;                       // O(1)
                cout << "Goles a buscar: ";      // O(1)
                cin >> goles;                    // O(1)
                cout << "\nJugadores con " << goles << " goles:" << endl;  // O(1)
                while (actual != nullptr) {      // O(n) - búsqueda lineal
                    if (actual->value.getGoles() == goles) {  // O(1)
                        actual->value.mostrar(); // O(1)
                        encontrado = true;       // O(1)
                    }
                    actual = actual->next;       // O(1)
                }
                break;
            }
            case 2: {
                int dorsal;                                                  // O(1)
                cout << "Dorsal a buscar: ";                                 // O(1)
                cin >> dorsal;                                               // O(1)
                cout << "\nJugadores con dorsal " << dorsal << ":" << endl;  // O(1)
                while (actual != nullptr) {                                  // O(n)
                    if (actual->value.getNumero() == dorsal) {               // O(1)
                        actual->value.mostrar();                             // O(1)
                        encontrado = true;                                   // O(1)
                    }
                    actual = actual->next;                                   // O(1)
                }
                break;
            }
            case 3: {
                string posicion;                                                // O(1)
                cout << "Posición a buscar: ";                                  // O(1)
                limpiarBuffer();                                                // O(1)
                getline(cin, posicion);                                         // O(1)
                cout << "\nJugadores en posición " << posicion << ":" << endl;  // O(1)
                while (actual != nullptr) {                                     // O(n) 
                    if (actual->value.getPosicion() == posicion) {              // O(1)
                        actual->value.mostrar();                                // O(1)
                        encontrado = true;                                      // O(1)
                    }
                    actual = actual->next;                                      // O(1)
                }
                break;
            }
            case 4: {
                int edad;                                                // O(1)
                cout << "Edad a buscar: ";                               // O(1)
                cin >> edad;                                             // O(1)
                cout << "\nJugadores con edad " << edad << ":" << endl;  // O(1)
                while (actual != nullptr) {                              // O(n)
                    if (actual->value.getEdad() == edad) {               // O(1)
                        actual->value.mostrar();                         // O(1)
                        encontrado = true;                               // O(1)
                    }
                    actual = actual->next;                               // O(1)
                }
                break;
            }
            default:
                cout << "Opción inválida!\n" << endl;  // O(1)
                return;                                // O(1)
        }

        if (!encontrado) {
            cout << "No se encontraron jugadores con los criterios especificados.\n" << endl;  // O(1)
        }
        // Complejidad total: O(n)
    }

    void mostrarMenu() {
        int opcion;                              // O(1)
        do {
            cout << "\n Bienvenido/a al:" << endl;  // O(1)
            cout << "\n - SISTEMA DE GESTIÓN DE JUGADORES FC BARCELONA -" << endl;  // O(1)
            cout << "\n Seleccione una opción:" << endl;  // O(1)
            cout << "1. Mostrar jugadores" << endl;       // O(1)
            cout << "2. Modificar jugadores" << endl;     // O(1)
            cout << "3. Encontrar jugador por..." << endl;// O(1)
            cout << "4. Guardar cambios y salir" << endl; // O(1)
            cout << "\nOpción: ";                 // O(1)
            cin >> opcion;                        // O(1)

            switch (opcion) {
                case 1:
                    mostrarJugadores();          // O(n log n)
                    break;
                case 2:
                    mostrarSubmenuModificar();   // O(n)
                    break;
                case 3:
                    buscarJugador();             // O(n)
                    break;
                case 4:
                    guardarJugadores();          // O(n)
                    cout << "Hasta luego!\n" << endl;  // O(1)
                    break;
                default:
                    cout << "Opción inválida!\n" << endl;  // O(1)
                    limpiarBuffer();              // O(1)
            }
        } while (opcion != 4);                  // O(k)
    }

private:
    void mostrarSubmenuModificar() {
        int opcion;                              // O(1)
        do {
            cout << "\n--- Modificar Jugadores ---" << endl;  // O(1)
            cout << "1. Agregar jugador" << endl;     // O(1)
            cout << "2. Eliminar jugador" << endl;    // O(1)
            cout << "3. Modificar datos de un jugador" << endl;  // O(1)
            cout << "4. Volver al menú principal" << endl;  // O(1)
            cout << "\nOpción: ";                 // O(1)
            cin >> opcion;                        // O(1)

            switch (opcion) {
                case 1:
                    agregarJugador();            // O(1)
                    break;
                case 2:
                    eliminarJugador();           // O(n)
                    break;
                case 3:
                    modificarJugador();          // O(n)
                    break;
                case 4:
                    cout << "Volviendo al menú principal...\n" << endl;  // O(1)
                    break;
                default:
                    cout << "Opción inválida!" << endl;  // O(1)
                    limpiarBuffer();              // O(1)
            }
        } while (opcion != 4);                  // O(k)
        // Complejidad total: O(n)
    }
};

#endif

/*
Complejidad general del archivo SistemaJugadores:
- Mejor caso: O(1) (en operaciones simples como agregar jugador)
- Caso promedio: O(n) (la mayoría de operaciones son búsquedas lineales)
- Peor caso: O(n log n) (cuando se muestra la lista ordenada)
*/