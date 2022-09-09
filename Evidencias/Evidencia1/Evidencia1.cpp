#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Log.h"

template <class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template<class T>
int getPivot(vector<T> &list, int start, int end) {
    // Opción 2 (Sin listas temporales)
    // Identificamos el pivote (El último elemento de la lista)
    T pivot = list[end];
    // Creamos un indice auxiliar igual a start -1 (auxIndex)
    int auxIndex = start - 1;
    // Recorremos toda la lista desde start hasta end - 1 (index)
    for (int index=start; index<=end-1; index++) {
        // Validamos si el valor de la lista en index es menor al pivot
        if (list[index]<pivot) {
            // si es menor
            // incrementamos el valor de auxIndex
            auxIndex++;
            // intercambiamos en la lista auxIndex con index
            swap(list, auxIndex, index);
        // else
            // no vamos a hacer nada
        }
    }
    // incrementamos el valor de auxIndex
    auxIndex++;
    // intercambiamos auxIndex con el pivot(end)
    swap(list, auxIndex, end);
    // regresar el valor de auxIndex
    return auxIndex;
}

template <class T>
void quickSort(vector<T> &list, int start, int end) {
    // Condición de control mientras start < end
    if (start < end) {
        // Encontrar el pivote y hacer las dos listas
        int pivot = getPivot(list, start, end);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, start, pivot - 1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot + 1, end);
    }
}

void printLog(vector<Log> logs){
    for (auto log : logs){
        cout << "UBI: " << log.ubi << " datetime: " << log.date << " " << log.time << endl;
    }
}

int main(){
    ifstream file;

    file.open("canalsuez.txt");

    string date;
    string time;
    string entry;
    string ubi;

    vector<Log> logs;

    while(file >> date >> time >> entry >> ubi){
        Log log(date, time, entry, ubi);
        logs.push_back(log);

    }

    quickSort(logs, 0, logs.size()-1);
    printLog(logs);

    return 0;
}