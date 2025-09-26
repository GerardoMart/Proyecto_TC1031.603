#ifndef SORTS_H
#define SORTS_H

#include <vector>
using namespace std;

template <class T>
class Sort {
public:
    // Búsqueda de forma secuencial
    int busqSecuencial(const vector<T> &v, T objetivo) { 
        for (int i = 0; i < v.size(); i++) { // O(n)
            if (v[i] == objetivo) {          // O(1)
                return i;                    // O(1)
            }
        }
        return -1; // O(1)
        // En el peor de los casos O(n) ya que recorre todos los espacios posibles
    }

    // Ordenación de tipo merge (Merge Sort)
    void merge(vector<T> &v, int izq, int mid, int der) {
        int n1 = mid - izq + 1; // O(1)
        int n2 = der - mid;     // O(1)

        vector<T> I(n1), D(n2); // O(n)

        for (int i = 0; i < n1; i++)          // O(n1)
            I[i] = v[izq + i];                // O(1)
        for (int j = 0; j < n2; j++)          // O(n2)
            D[j] = v[mid + 1 + j];            // O(1)

        int i = 0, j = 0, k = izq;            // O(1)

        while (i < n1 && j < n2) {            // O(n)
            if (I[i] <= D[j]) {               // O(1)
                v[k] = I[i];                  // O(1)
                i++;                          // O(1)
            } else {
                v[k] = D[j];                  // O(1)
                j++;                          // O(1)
            }
            k++;                              // O(1)
        }

        while (i < n1) {                      // O(n1)
            v[k] = I[i];                      // O(1)
            i++; k++;                         // O(1)
        }
        while (j < n2) {                      // O(n2)
            v[k] = D[j];                      // O(1)
            j++; k++;                         // O(1)
        }
    }

    void mergeSort(vector<T> &v, int izq, int der) {
        if (izq < der) {                                        // O(1)
            int mid = izq + (der - izq) / 2;                    // O(1)

            mergeSort(v, izq, mid);                             // O(n log n)
            mergeSort(v, mid + 1, der);                         // O(n log n)

            merge(v, izq, mid, der);                            // O(n)
        }
    }

    void ordenaMerge(vector<T> &v) {
        mergeSort(v, 0, v.size() - 1);  // O(n log n)
    }
    // Complejidad total: O(n log n) en el peor de los casos
};

#endif
