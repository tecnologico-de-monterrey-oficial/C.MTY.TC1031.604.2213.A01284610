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

template <class T>
int sequentialDiffSearch(vector<T> list, int index) {
    int i = index;
    while (i > 0 && strcmp(list[i-1].ubi.substr(0,3).c_str(), list[i].ubi.substr(0,3).c_str())==0){
        i--;
    }
    return i;
}

template <class T>
void sequentialPrintRun(vector<T> list, int index) {
    int i = index;
    bool loop = true;

    while (loop){
        printLog(list,i);
        if (!(i < list.size()-1) || !(strcmp(list[i].ubi.substr(0,3).c_str(), list[i+1].ubi.substr(0,3).c_str())==0)){
            loop = false;
        }
        i++;
    }
    return;
}


template <class T>
bool binarySearch(vector<T> list, string value) {
    // Definir el límite inferior
    int left = 0;
    // Definir el límite superior
    int right = list.size() - 1;
    // Iterar en la lista mientras el límite inferior <= limite superior
    while (left <= right) {
        // Calculo la posición del índice de en medio (limite inferior + limite superior) / 2
        int mid = (left + right) / 2;
        // Reviso si el valor búscado es igual el elemento de la posición del índice de en medio
        if (list[mid]==value) {

            //Busqueda secuencial hacia arriba
            int startIndex = sequentialDiffSearch(list, mid);
            sequentialPrintRun(list, startIndex);
            return true;

        } else {
            // Si no es igual
            // Reviso si valor buscado es menor al elemento de la posición del índice de en medio
            if (list[mid]>value) {
                // Si es menor
                // actualizo el límite superior con el valor del índice de en medio - 1
                right = mid -1;
            } else {
                // Si es mayor
                // actualizo el límite inferior con el valor del índice de en medio + 1
                left = mid + 1;
            }
        }
    }
    // Cuando me salga del ciclo
    // Regreso falso
    return false;
}

void printAllLogs(vector<Log> logs){
    for (auto log : logs){
        cout << "UBI: " << log.ubi << " datetime: " << log.date << " " << log.time << endl;
    }
}

void printLog(vector<Log> logs, int i){
    cout << "UBI: " << logs[i].ubi << " datetime: " << logs[i].date << " " << logs[i].time << endl;
}

int main(){
    ifstream file;
    string fileName, searchUbi;
    bool loop = true;
    bool loop2 = true;

    while (loop){
        cout << "\nIngrese el nombre del archivo con los datos incluyendo la terminación de la extención: " << endl;
        cin >> fileName;
        fileName.c_str();

        ifstream fileCheck(fileName);

        if(fileCheck.good()){
            loop = false;
        } else {
            cout << "No se encontró el archivo, ingrese el nombre otra vez." << endl;
        }

        fileCheck.close();
    }

    file.open(fileName);
    
    string date;
    string time;
    string entry;
    string ubi;

    vector<Log> logs;

    while(file >> date >> time >> entry >> ubi){
        Log log(date, time, entry, ubi);
        logs.push_back(log);

    }

    //sorting de logs
    quickSort(logs, 0, logs.size()-1);

    while(loop2){
        cout << "\nIngrese los primeros 3 caracteres del UBI que desea buscar o 'exit' para dejar de buscar: " << endl;
        cin >> searchUbi;

        if (strcmp(searchUbi.c_str(), "exit")==0){
            cout << "Muchas Gracias" << endl;
            return 0;
            file.close();
        }

        if (!(binarySearch(logs, searchUbi))){
        cout << "No se pudo encontrar el UBI" << endl;
        }
    }


    return 0;
}