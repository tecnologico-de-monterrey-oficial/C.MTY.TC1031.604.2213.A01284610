#include <iostream>
#include <fstream>
#include "Log.h"
#include <vector>
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"


using namespace std;

template<class T>
void HeapSortD(vector<T>& list) {
    // Creamos un heap en base a la lista
    Heap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

template<class T>
void HeapSortA(vector<T>& list) {
    // Creamos un heap en base a la lista
    MinHeap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

void printAllLogs(vector<Log> logs){
    for (auto log : logs){
        cout << log.entry << " UBI: " << log.ubi << " datetime: " << log.date << " " << log.time << endl;
    }
}

void print10Logs(vector<Log> logs){
    int count = 0;
    for (auto log : logs){
        if (count < 10){
        cout << log.entry << " UBI: " << log.ubi << " datetime: " << log.date << " " << log.time << endl;
        count++;
        }
    }
}

void printLog(vector<Log> logs, int i){
    cout << "UBI: " << logs[i].ubi << " datetime: " << logs[i].date << " " << logs[i].time << endl;
}

int main(){
    ifstream file;
    string fileName, searchUbi;
    int option = 0;
    int option2 = 0;
    bool loop = true;
    bool loop2 = true;
    bool loop3 = true;


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

    vector<Log> logsM;
    vector<Log> logsR;
    vector<Log> logsCopy;
    BST<Log> tree;


    while(file >> date >> time >> entry >> ubi){

        Log log(date, time, entry, ubi);

        if (entry == "M"){
            logsM.push_back(log);
        } else if (entry == "R"){
            logsR.push_back(log);
        }

        tree.insert(log);
    }

    while (loop2)
    {
        loop3 = true;
        cout << "\nSeleccione la opción que busca:" << endl;
        cout << "1. Despielgue de Mar Mediterraneo" << endl;
        cout << "2. Despielgue de Mar Rojo" << endl;
        cout << "3. Busqueda de UBI" << endl;
        cout << "0. Salir del programa" << endl;
        cin >> option;
        cin.clear();
        cout << "\n";

        switch (option)
        {
        case 1:
            while (loop3)
            {
                logsCopy = logsM;
                cout << "\nSeleccione la opción que busca:" << endl;
                cout << "1. Despielgue en orden mayor a menor" << endl;
                cout << "2. Despielgue en orden menor a mayor" << endl;
                cout << "0. Regresar" << endl;
                cin >> option2;
                cin.clear();
                switch (option2)
                {
                case 1:
                    HeapSortD(logsCopy);
                    printAllLogs(logsCopy);
                    loop3 = false;
                    break;
                case 2:
                    HeapSortA(logsCopy);
                    printAllLogs(logsCopy);
                    loop3 = false;
                    break;
                case 0:
                    cout << "retornando..." << endl;
                    loop3 = false;
                    break;
                default:
                        cout << "--Input invalido, vuelva a ingresar la opción" << endl;
                    break;
                }
            }
            break;
        case 2:
        while (loop3)
            {
                logsCopy = logsR;
                cout << "\nSeleccione la opción que busca:" << endl;
                cout << "1. Despielgue en orden mayor a menor" << endl;
                cout << "2. Despielgue en orden menor a mayor" << endl;
                cout << "0. Regresar" << endl;
                cin >> option2;
                cin.clear();
                switch (option2)
                {
                case 1:
                    HeapSortD(logsCopy);
                    printAllLogs(logsCopy);
                    loop3 = false;
                    break;
                case 2:
                    HeapSortA(logsCopy);
                    printAllLogs(logsCopy);
                    loop3 = false;
                    break;
                case 0:
                    cout << "retornando..." << endl;
                    loop3 = false;
                    break;
                default:
                        cout << "--Input invalido, vuelva a ingresar la opción" << endl;
                    break;
                }
            }
            break;
        case 3:
            while(loop3){
                cout << "\nIngrese el UBI que desea buscar o '0' para dejar de buscar: " << endl;
                cin >> searchUbi;
                cin.clear();

                if (strcmp(searchUbi.c_str(), "0")==0){
                    cout << "retornando..." << endl;
                    loop3 = false;
                } else {
                // if (!(searchManager(logsM, logsR, searchUbi))){
                // cout << "No se pudo encontrar el UBI" << endl;
                // }

                if (!(tree.find(Log("00-00-00","00:00","X",searchUbi)))){
                    cout << "No se pudo encontrar el UBI" << endl;
                    }
                }

            }
            break;
        case 0:
        cout << "Muchas Gracias" << endl;
        loop2 = false;
            break;
        default:
        cout << "--Input invalido, vuelva a ingresar la opción" << endl;
            break;
        }
    }

    return 0;
}