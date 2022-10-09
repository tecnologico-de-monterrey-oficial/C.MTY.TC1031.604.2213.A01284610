#include <iostream>
#include <fstream>

using namespace std;

#include "Log.h"
#include "DoublyLinkedList.h"

template <class T>
void swap(DoublyLinkedList<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template<class T>
int getPivot(DoublyLinkedList<T> &list, int start, int end) {
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
void quickSort(DoublyLinkedList<T> &list, int start, int end) {
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
int sequentialDiffSearch(DoublyLinkedList<T> list, int index) {
    int i = index;
    
    if (index == 0){
        return index;
    }

    while (i > 0 && strcmp(list[i-1].ubi.substr(0,3).c_str(), list[i].ubi.substr(0,3).c_str())==0){
        i--;
    }
    return i;
}

template <class T>
int_fast32_t binarySearch(DoublyLinkedList<T> list, string value) {
    // Definir el límite inferior
    int left = 0;
    // Definir el límite superior
    int right = list.getSize() - 1;
    // Iterar en la lista mientras el límite inferior <= limite superior
    while (left <= right) {
        // Calculo la posición del índice de en medio (limite inferior + limite superior) / 2
        int mid = (left + right) / 2;
        // Reviso si el valor búscado es igual el elemento de la posición del índice de en medio
        if (list[mid]==value) {

            //Busqueda secuencial hacia arriba
            return sequentialDiffSearch(list, mid);;

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
    return -1;
}

template <class T>
bool searchManager(DoublyLinkedList<T> logsM, DoublyLinkedList<T> logsR, string ubi){

    bool loopM = true;
    bool loopR = true;

    bool sameM = true;
    bool sameR = true;

    int countM = 0;
    int countR = 0;

    int indexM = binarySearch(logsM,ubi);
    int indexR = binarySearch(logsR,ubi);
    int month = 0;
    int year = 0;


    if (indexM == -1 && indexR == -1){
        return false;
    }
    
    //encontrar la fecha mas temprana de either entry
    if (indexM == -1){
        //R has values
        month = logsR[indexR].month;
        year = logsR[indexR].year;
        loopM = false;
        // cout << "el menor es R y:" << year << " m:" << month << "entre R" << endl;
    } else if (indexR == -1){
        //M has values
        month = logsM[indexM].month;
        year = logsM[indexM].year;
        loopR = false;
        // cout << "el menor es M y:" << year << " m:" << month << "entre M" << endl;

    } else {
        //both have values
        if (logsR[indexR].newdate < logsM[indexM].newdate){
            month = logsR[indexR].month;
            year = logsR[indexR].year;
            // cout << "el menor es R y:" << year << " m:" << month << "entre M&R" << endl;
        }else{
            month = logsM[indexM].month;
            year = logsM[indexM].year;
            // cout << "el menor es M y:" << year << " m:" << month << "entre M&R" << endl;
        }
    }
    //buscar por cada mes secuencial y sumar counter la cantidad de entries cada


    string months[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dic"};

    while (loopR || loopM){
        if (loopM){
            if (!(indexM < logsM.getSize()-1) || !(strcmp(logsM[indexM].ubi.substr(0,3).c_str(), ubi.c_str())==0)){
                loopM = false;
            } 
        }

        if (loopR){
            if (!(indexR < logsR.getSize()-1) || !(strcmp(logsR[indexR].ubi.substr(0,3).c_str(), ubi.c_str())==0)){
                loopR = false;
            } 
        }

        // cout << "looking into year: " << year << " month: " << month << endl;

        while (loopM && sameM){
            // cout << "M: yr" << logsM[indexM].year << " mth" << logsM[indexM].month << " ubi" << logsM[indexM].ubi << endl;
            if (logsM[indexM].month == month && logsM[indexM].year == year){
                countM++;
                // cout << "foundM ";
                indexM++;
            } else {
                sameM = false;
            }
        }

        while (loopR && sameR){
            // cout << "R: yr" << logsR[indexR].year << " mth" << logsR[indexR].month << " ubi" << logsR[indexR].ubi << endl;
            if (logsR[indexR].month == month && logsR[indexR].year == year){
                countR++;
                // cout << "foundR ";
                indexR++;
            } else {
                sameR = false;
            }
        }

        if (loopM || loopR){
            cout << months[month-1] << " " << year << " M:"  << countM << " R:"  << countR << endl;
        }
        countM = 0;
        countR = 0;
        sameM = true;
        sameR = true;
        if (month == 12){
            year = (year+1)%100;
        }
        month = (month)%12+1;
    }
    return true;
}

void printLog(DoublyLinkedList<Log> logs, int i){
    cout << "UBI: " << logs[i].ubi << " datetime: " << logs[i].date << " " << logs[i].time << endl;
}

int main(){
    ifstream file;
    string fileName, searchUbi;
    bool loop = true;
    bool loop2 = true;

    while (loop){
        cout << "\nIngrese el nombre del archivo con los datos incluyendo la terminación de la extención: " << endl;
        cout << "(o 'exit' para salir del programa)" << endl;
        cin >> fileName;

        if (strcmp(fileName.c_str(), "exit")==0){
            cout << "Muchas Gracias" << endl;
            return 0;
            file.close();
        }

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

    DoublyLinkedList<Log> logsM;
    DoublyLinkedList<Log> logsR;


    while(file >> date >> time >> entry >> ubi){

        Log log(date, time, entry, ubi);

        if (entry == "M"){
            logsM.append(log);
        } else if (entry == "R"){
            logsR.append(log);
        }

    }

    //sorting de logs
    quickSort(logsM, 0, logsM.getSize()-1);
    quickSort(logsR, 0, logsR.getSize()-1);


    while(loop2){
        cout << "\nIngrese los primeros 3 caracteres del UBI que desea buscar o 'exit' para dejar de buscar: " << endl;
        cin >> searchUbi;

        if (strcmp(searchUbi.c_str(), "exit")==0){
            cout << "Muchas Gracias" << endl;
            return 0;
            file.close();
        }

        if (!(searchManager(logsM, logsR, searchUbi))){
        cout << "No se pudo encontrar el UBI" << endl;
        }
    }


    return 0;
}