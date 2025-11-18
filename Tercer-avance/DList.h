#ifndef DLIST_H_
#define DLIST_H_

#include <sstream>
#include <string>
#include <stdexcept>

//Clase del nodo o "link" doblemente encadenada
template <class T>
class DLink {
public:
    T value;                  // O(1)
    DLink<T>* next;           // O(1)
    DLink<T>* prev;           // O(1)

    //Constructor del nodo
    DLink(T val, DLink<T>* nxt = 0, DLink<T>* prv = 0) : value(val), next(nxt), prev(prv) {} // O(1)
};

//Clase de la lista doblemente encadenada
template <class T>
class DList {
private:
    DLink<T>* head;           // O(1)
    DLink<T>* tail;           // O(1)
    int size;                 // O(1)

    template <class U> friend class Sort;

public:
    //Constructor
    DList();                  // O(1)
    //Destructor
    ~DList();                 // O(n)

    //Métodos de la clase
    void insertion(T val);                // O(1)
    int search(T val) const;              // O(n)
    void update(int pos, T val);          // O(n)
    T deleteAt(int pos);                  // O(n)
    std::string toStringForward() const;  // O(n)
    std::string toStringBackward() const; // O(n)

    //¿Está vacía la lista?
    bool empty() const { return head == 0; } // O(1)

    //Borrar elementos de la lista
    void clear();             // O(n)

    DLink<T>* getHead() const { return head; } // O(1)
};

//Constructor que inicializa la lista
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {} // O(1)

//Destructor: limpia la lista
template <class T>
DList<T>::~DList() {
    clear(); // O(n)
}

//Limpiar toda la lista liberando memoria
template <class T>
void DList<T>::clear() {
    DLink<T>* puntero;              // O(1)
    while (head != 0) {             // O(n)
        puntero = head;             // O(1)
        head = head->next;          // O(1)
        delete puntero;             // O(1)
    }
    tail = 0;                       // O(1)
    size = 0;                       // O(1)
    // Complejidad total: O(n)
}

//Insertar un nuevo elemento al final de la lista
template <class T>
void DList<T>::insertion(T val) {
    DLink<T>* nuevo = new DLink<T>(val); // O(1)

    if (empty()) {              // O(1)
        head = tail = nuevo;    // O(1)
    } else {
        tail->next = nuevo;     // O(1)
        nuevo->prev = tail;     // O(1)
        tail = nuevo;           // O(1)
    }
    size++;                     // O(1)
    // Complejidad total: O(1)
}

//Buscar un elemento y devuelve su posición (o -1 si no existe)
template <class T>
int DList<T>::search(T val) const {
    DLink<T>* puntero = head;   // O(1)
    int pos = 0;                // O(1)

    while (puntero != 0) {           // O(n)
        if (puntero->value == val) { // O(1)
            return pos;              // O(1)
        }
        puntero = puntero->next;     // O(1)
        pos++;                       // O(1)
    }
    return -1;                       // O(1)
    // Complejidad total: O(n)
}

//Actualizar el valor en una posición dada
template <class T>
void DList<T>::update(int pos, T val) {
    if (pos < 0 || pos >= size) {           // O(1)
        throw std::out_of_range("Fuera de rango"); // O(1)
    }

    DLink<T>* puntero = head;               // O(1)
    int index = 0;                          // O(1)
    while (puntero != 0) {                  // O(n)
        if (index == pos) {                 // O(1)
            puntero->value = val;           // O(1)
            return;                         // O(1)
        }
        puntero = puntero->next;            // O(1)
        index++;                            // O(1)
    }
    // Complejidad total: O(n)
}

//Eliminar el nodo en la posición indicada
template <class T>
T DList<T>::deleteAt(int pos) {
    if (pos < 0 || pos >= size || empty()) {   // O(1)
        throw std::out_of_range("Fuera de rango"); // O(1)
    }

    DLink<T>* puntero = head;                  // O(1)
    T val;                                     // O(1)

    if (pos == 0) {                            // O(1)
        val = head->value;                     // O(1)
        head = head->next;                     // O(1)
        if (head != 0) {                       // O(1)
            head->prev = 0;                    // O(1)
        } else {
            tail = 0;                          // O(1)
        }
        delete puntero;                        // O(1)
        size--;                                // O(1)
        return val;                            // O(1)
    }

    int index = 0;                             // O(1)
    while (index < pos && puntero != 0) {      // O(n)
        puntero = puntero->next;               // O(1)
        index++;                               // O(1)
    }

    val = puntero->value;                      // O(1)

    if (puntero->prev != 0) {                  // O(1)
        puntero->prev->next = puntero->next;   // O(1)
    }
    if (puntero->next != 0) {                  // O(1)
        puntero->next->prev = puntero->prev;   // O(1)
    } else {
        tail = puntero->prev;                  // O(1)
    }

    delete puntero;                            // O(1)
    size--;                                    // O(1)
    return val;                                // O(1)
    // Complejidad total: O(n)
}

//Devolver el contenido como string hacia adelante
template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;             // O(1)
    DLink<T>* puntero = head;          // O(1)

    aux << "[";                        // O(1)
    while (puntero != 0) {             // O(n)
        aux << puntero->value;         // O(1)
        if (puntero->next != 0) {      // O(1)
            aux << ", ";               // O(1)
        }
        puntero = puntero->next;       // O(1)
    }
    aux << "]";                        // O(1)
    return aux.str();                  // O(n)
    // Complejidad total: O(n)
}

//Devolver el contenido como string hacia atrás
template <class T>
std::string DList<T>::toStringBackward() const {
    std::stringstream aux;             // O(1)
    DLink<T>* puntero = tail;          // O(1)

    aux << "[";                        // O(1)
    while (puntero != 0) {             // O(n)
        aux << puntero->value;         // O(1)
        if (puntero->prev != 0) {      // O(1)
            aux << ", ";               // O(1)
        }
        puntero = puntero->prev;       // O(1)
    }
    aux << "]";                        // O(1)
    return aux.str();                  // O(n)
    // Complejidad total: O(n)
}

#endif

/*
Complejidad general del archivo DList:
- Mejor caso: O(1)
- Caso promedio: O(n)
- Peor caso: O(n)
*/