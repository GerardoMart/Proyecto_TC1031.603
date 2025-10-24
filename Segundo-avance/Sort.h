#ifndef SORT_H
#define SORT_H

#include "DList.h"

template <class T>
class Sort {
private:
    // Divide la lista en dos mitades
    DLink<T>* split(DLink<T>* head) {
        DLink<T>* slow = head;                       // O(1)
        DLink<T>* fast = head;                       // O(1)
        while (fast->next && fast->next->next) {     // O(n)
            slow = slow->next;                       // O(1)
            fast = fast->next->next;                 // O(1)
        }
        DLink<T>* second = slow->next;               // O(1)
        slow->next = nullptr;                        // O(1)
        if (second) second->prev = nullptr;          // O(1)
        return second;                               // O(1)
        // Complejidad total: O(n)
    }

    // Mezcla dos listas ordenadas
    DLink<T>* merge(DLink<T>* first, DLink<T>* second) {
        if (!first) return second;                   // O(1)
        if (!second) return first;                   // O(1)

        if (first->value <= second->value) {         // O(1)
            first->next = merge(first->next, second); // O(n)
            if (first->next) first->next->prev = first; // O(1)
            first->prev = nullptr;                   // O(1)
            return first;                            // O(1)
        } else {
            second->next = merge(first, second->next); // O(n)
            if (second->next) second->next->prev = second; // O(1)
            second->prev = nullptr;                  // O(1)
            return second;                           // O(1)
        }
        // Complejidad total: O(n)
    }

    // Merge sort recursivo
    DLink<T>* mergeSort(DLink<T>* head) {
        if (!head || !head->next)                    // O(1)
            return head;                             // O(1)

        DLink<T>* second = split(head);              // O(n)
        head = mergeSort(head);                      // O(n log n)
        second = mergeSort(second);                  // O(n log n)
        return merge(head, second);                  // O(n)
        // Complejidad total: O(n log n)
    }

public:
    void ordenaMerge(DList<T> &lista) {
        if (lista.empty()) return;                   // O(1)

        // Ordena y actualiza los punteros de la lista
        lista.head = mergeSort(lista.head);          // O(n log n)

        // Actualiza el tail recorriendo hasta el final
        DLink<T>* tail = lista.head;                 // O(1)
        while (tail && tail->next)                   // O(n)
            tail = tail->next;                       // O(1)
        lista.tail = tail;                           // O(1)
        // Complejidad total: O(n log n)
    }
};

#endif

/*
Complejidad general del archivo Sort:
- Mejor caso: O(n log n)
- Caso promedio: O(n log n)
- Peor caso: O(n log n)
*/