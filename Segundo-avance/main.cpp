#include <iostream>
#include <fstream>
#include <string>
#include "Jugador.h"
#include "Sort.h"
#include "DList.h"
using namespace std;

int main() {
    DList<Jugador> jugadores;
    ifstream archivo("Lista.txt");

    if (!archivo) {
        cout << "No se pudo abrir el archivo con la lista de jugadores.\n";
        return 1;
    }

    string nombre, posicion;
    int dorsal, edad, goles;

    // Leer jugadores del archivo y agregarlos a la lista doblemente ligada
    while (archivo >> nombre >> dorsal >> posicion >> edad >> goles) {
        jugadores.insertion(Jugador(nombre, dorsal, posicion, edad, goles));
    }
    archivo.close();

    Sort<Jugador> s;

    auto mostrarLista = [&](string titulo) {
        cout << "\n" << titulo << ":\n";
        DLink<Jugador>* ptr = jugadores.getHead();
        while (ptr != nullptr) {
            ptr->value.mostrar();
            ptr = ptr->next;
        }
    };

    cout << "Lista original:\n";
    mostrarLista("Jugadores");

    // Por nombre
    Jugador::setCriterio(0);
    s.ordenaMerge(jugadores);
    mostrarLista("Ordenados por nombre");

    // Por goles (mayor a menor)
    Jugador::setCriterio(1);
    s.ordenaMerge(jugadores);
    mostrarLista("Ordenados por goles (mayor a menor)");

    // Por dorsal
    Jugador::setCriterio(2);
    s.ordenaMerge(jugadores);
    mostrarLista("Ordenados por dorsal");

    // Por posición
    Jugador::setCriterio(3);
    s.ordenaMerge(jugadores);
    mostrarLista("Ordenados por posición");

    // Por edad
    Jugador::setCriterio(4);
    s.ordenaMerge(jugadores);
    mostrarLista("Ordenados por edad");

    return 0;
}