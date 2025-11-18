#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
    string nombre;   // O(1)
    int numero;      // O(1)
    string posicion; // O(1)
    int edad;        // O(1)
    int goles;       // O(1)

    // Criterio para el ordenamiento
    static int criterio;  // O(1)

    // Conversión de posición a un valor numérico
    int valorPosicion() const {
        if (posicion == "Portero") return 0;          // O(1)
        if (posicion == "Defensa") return 1;          // O(1)
        if (posicion == "Mediocampista") return 2;    // O(1)
        if (posicion == "Delantero") return 3;        // O(1)
        return 4;  // O(1)
        // Complejidad total: O(1)
    }

public:
    // Constructores
    Jugador() {}  // O(1)
    
    Jugador(string n, int num, string pos, int e, int g) {
        nombre = n;      // O(1)
        numero = num;    // O(1)
        posicion = pos;  // O(1)
        edad = e;        // O(1)
        goles = g;       // O(1)
        // Complejidad total: O(1)
    }

    void setNumero(int num) { numero = num; }          // O(1)
    void setPosicion(string pos) { posicion = pos; }   // O(1)
    void setEdad(int e) { edad = e; }                  // O(1)
    void setGoles(int g) { goles = g; }                // O(1)

    string getNombre() const { return nombre; }     // O(1)
    int getNumero() const { return numero; }        // O(1)
    string getPosicion() const { return posicion; } // O(1)
    int getEdad() const { return edad; }            // O(1)
    int getGoles() const { return goles; }          // O(1)

    // Método estático para cambiar el criterio de comparación
    static void setCriterio(int c) { 
        criterio = c;  // O(1)
        // Complejidad total: O(1)
    }

    // Sobrecarga de operador <= según criterio
    bool operator<=(const Jugador &otro) const {
        if (criterio == 0) return nombre <= otro.nombre;                   // O(1)
        if (criterio == 1) return goles >= otro.goles;                     // O(1)
        if (criterio == 2) return numero <= otro.numero;                   // O(1)
        if (criterio == 3) return valorPosicion() <= otro.valorPosicion(); // O(1)
        if (criterio == 4) return edad <= otro.edad;                       // O(1)
        return false;                                                      // O(1)
        // Complejidad total: O(1)
    }

    // Mostrar datos del jugador
    void mostrar() const {
        cout << "Nombre: " << nombre           // O(1)
             << ", Numero: " << numero         // O(1)
             << ", Posicion: " << posicion     // O(1)
             << ", Edad: " << edad             // O(1)
             << ", Goles: " << goles << endl;  // O(1)
        // Complejidad total: O(1)
    }

    // Para búsqueda y comparación
    bool operator==(const Jugador& otro) const {
        return nombre == otro.nombre;  // O(1)
        // Complejidad total: O(1)
    }
};

// Inicialización del criterio por defecto
int Jugador::criterio = 0; // O(1)

#endif

/*
Complejidad general del archivo Jugador:
- Mejor caso: O(1)
- Caso promedio: O(1)
- Peor caso: O(1)
*/