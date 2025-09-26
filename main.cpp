#include <iostream>
#include <fstream>
#include <vector>
#include "Jugador.h"
#include "Sort.h"
using namespace std;

int main() {
    vector<Jugador> jugadores;
    ifstream archivo("Lista.txt"); // Abrimos el archivo con la lista de jugadores

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo con la lista de jugadores.\n";
        return 1;
    }

    string nombre, posicion;
    int dorsal, edad, goles;

    // Leer datos del archivo ordenando por características de los jugadores
    while (archivo >> nombre >> dorsal >> posicion >> edad >> goles) {
        jugadores.push_back(Jugador(nombre, dorsal, posicion, edad, goles)); // Ordenar las características en el vector<Jugador>
    }

    archivo.close();

    // Creación de objeto de clase Sort (Merge Sort) en base a la clase Jugador
    Sort<Jugador> s;

    cout << "Lista original:\n";
    for (auto &j : jugadores) j.mostrar();

    // Ordenación por nombre
    Jugador::setCriterio(0);
    s.ordenaMerge(jugadores);
    cout << "\nOrdenados por nombre:\n";
    for (auto &j : jugadores) j.mostrar();

    // Ordenación por goles (mayor a menor)
    Jugador::setCriterio(1);
    s.ordenaMerge(jugadores);
    cout << "\nOrdenados por goles (Mayor a menor):\n";
    for (auto &j : jugadores) j.mostrar();

    // Ordenación por dorsal
    Jugador::setCriterio(2);
    s.ordenaMerge(jugadores);
    cout << "\nOrdenados por dorsal:\n";
    for (auto &j : jugadores) j.mostrar();

    // Ordenación por posición
    Jugador::setCriterio(3);
    s.ordenaMerge(jugadores);
    cout << "\nOrdenados por posicion (Portero, Defensa, Mediocampista, Delantero):\n";
    for (auto &j : jugadores) j.mostrar();

    // Ordenación por edad
    Jugador::setCriterio(4);
    s.ordenaMerge(jugadores);
    cout << "\nOrdenados por edad:\n";
    for (auto &j : jugadores) j.mostrar();

    return 0;
}
