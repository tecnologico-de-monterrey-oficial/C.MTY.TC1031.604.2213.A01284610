#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;

int main(){
    ifstream file;
    string fileName;
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

    portGraph.Dijkstra("Ambarli", "Bandar");
    portGraph.DijkstraReverse("Ambarli", "Bandar");


    cout << "lol\n";
    portGraph.Dijkstra("Ambarli", "Cartagena");
    cout << "lol2\n";
    portGraph.Dijkstra("Ambarli", "iauhsdhiudashiuasd");
    cout << "lol3\n";
    portGraph.Dijkstra("Ambarli", "Ambarli");


    return 0;
}