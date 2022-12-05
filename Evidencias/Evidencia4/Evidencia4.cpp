#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;

void menu1(){
        cout << "\n==[MENU]==" << endl;
        cout << "1. Despielgue Puertos" << endl;
        cout << "2. Ingresar Puertos" << endl;
        cout << "0. Salir" << endl;

}

int main(){
    ifstream file;
    string fileName;
    int option = 0;
    string strOption, strOption2;
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
            cout << " WARNING: No se encontró el archivo, ingrese el nombre otra vez." << endl;
        }

        fileCheck.close();
    }

    file.open(fileName);

    int portCount, routeCount;
    string source, target, weight;
    vector< Vertex<string> > tempVertices;
    vector< string > tempPort;

    file >> routeCount;

    for (int i = 0; i < routeCount; i++){
        file >> source >> target >> weight;
        tempVertices.push_back(Vertex<string>(source, target, stoi(weight)));
    }

    file >> portCount;

    for (int i = 0; i < portCount; i++){
        file >> source;
        tempPort.push_back(source);
    }

    Graph<string> portGraph(tempPort, tempVertices);

    
    while (true){
        menu1();
        cin >> option;
        cin.clear();
        cout << "\n";
        
        switch (option)
        {
        case 1:
            portGraph.printVertices();
            break;
        
        case 2:
            loop = true;
            while(loop){
                cout << "Ingrese el puerto de SALIDA o 'return' para salir" << endl;
                cin >> strOption;
                cin.clear();
                if (strOption == "return"){
                    loop = false;
                } else {
                    cout << "Ingrese el puerto de ENTRADA o 'return' para salir" << endl;
                    loop2 = true;
                    while (loop2){
                        cin >> strOption2;
                        cin.clear();
                        if (strOption2 == "return"){
                            loop2 = false;
                        } else {
                            portGraph.Dijkstra(strOption,strOption2);
                            loop2 = false;
                        }
                    }
                }
            }
            break;

        case 0:
            cout << "Muchas Gracias" <<  endl;
            return 0;
            break;
        
        default:
        cout << " WARNING: Hubo un error con la seleccion de opcion" << endl;
            break;
        }
    }


    // cout << "\n\nNormal" << endl; 
    // portGraph.Dijkstra("Ambarli", "Bandar");

    return 0;
}