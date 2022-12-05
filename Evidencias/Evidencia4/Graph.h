#ifndef Graph_h
#define Graph_h

#include <queue>

#include "Vertex.h"
#include "HashPort.h"

template<class T>
class Graph {
private:
    vector< vector< Vertex<T> > > graph;
    HashPort vertices;
    int size = 37;
    int portCount = 0;
    int findVertex(T vertex);
    int getSmallIndex(vector<bool> status, vector<int> cost);

public:
    Graph();
    Graph(vector<T> vertices);
    Graph(vector<T> vertices, vector< Vertex<T> > edges);
    // void addEdges(vector< Vertex<T> > edges);
    // void addEdge(Vertex<T> edge);
    // void addVertex(T vertex); // dejar pendiente
    // void BFS(T vertex);
    // void DFS(T Vertex); // Depth First Search
    // void DFSR(int index, vector<bool> &status); 
    // void print();
    void Dijkstra(T vertex, T dest);

    void DijkstraReverse(T vertex, T dest);

};

// Constructor por default
template<class T>
Graph<T>::Graph() {
    size = 0;
}

// Constructor con lista de vertices
template<class T>
Graph<T>::Graph(vector<T> vertices_) {
    for (auto port: vertices_){
        vertices.addPort(port);
    }
}

template<class T>
Graph<T>::Graph(vector<T> vertices_, vector< Vertex<T> > edges) {
    portCount = vertices_.size();

    for (auto port: vertices_){
        vertices.addPort(port);
    }

    // Cambiamos el tamaño de la matriz graph para almacenar todos los vertices
    graph.resize(size);
    // iteramos en la lista de arcos para agregar cada arco
    for (auto edge : edges) {
        // buscar el indice del arco origen en la lista de vértices
        int sourceIndex = findVertex(edge.source);
        if (sourceIndex == -1) {
            throw out_of_range("El vértice no se encuentra en el grafo");
            return;
        }
        // agregamos el vertex en la poisición del sourceIndex en el grafo
        graph[sourceIndex].push_back(edge);
    }
}

template<class T>
int Graph <T>::findVertex(T vertex) {
    return vertices.hashFunction(vertex);
}

// template<class T>
// void Graph<T>::BFS(T vertex) {
//     // Creamos una vector del mismo tamaño del vector de vertices con valores boleanos inizializado en falso
//     vector<bool> status(size, false);
//     // Creamos una fila de tipo entero vacía
//     queue<int> adjQueue;
//     // Buscar el índice del vértice inicial (index)
//     int index = findVertex(vertex);
//     // validamos si existe
//     if (index >= 0) {
//         // si existe
//         // agregamos el índice a la fila
//         adjQueue.push(index);
//         // cambiamos el estado del índice del vértice inicial en la lista de estados 
//         status[index] = true;
//         // Ciclo mientras la lista no este vacía
//         while (!adjQueue.empty()) {
//             // Obtenemos el elemento del principio de la fila
//             index = adjQueue.front();
//             // Imprimimos el nodo
//             cout << vertices[index] << " ";
//             // Recorremos todos los nodos adyacentes
//             for (auto adjVertex : graph[index]) {
//                 // Buscamos el índice del nodo adyacente (adjIndex)
//                 int adjIndex = findVertex(adjVertex.target);
//                 // Revisamos el valor en la lista de estados de ese índice
//                 if (!status[adjIndex]) {
//                     // si es falso
//                     // agregamos el índice a la fila
//                     adjQueue.push(adjIndex);
//                     // cambiamos a verdado el valor de ese índice en la lista de estados
//                     status[adjIndex] = true;
//                 }
//             }
//             // Sacamos el nodo de la fila
//             adjQueue.pop();
//         }
//     }


// }

// template<class T>
// void Graph<T>::DFS(T vertex){
//     int index = findVertex(vertex);

//     if (index >= 0){
//         vector<bool> status(size,false);
//         DFSR(index,status);
//     }

// }

// template<class T>
// void Graph<T>::DFSR(int index, vector<bool> &status){
//     cout << vertices[index] << " ";

//     status[index] = true;
//     for (auto adj : graph[index]){
//         int adjIndex = findVertex(adj.target);
        
//         if (!status[adjIndex]){
//             DFSR(adjIndex,status);
//             cout << endl;
//         }

//     }
// }

// template<class T>
// void Graph<T>::print() {
//     for (int i=0; i<size; i++) {
//         cout << vertices[i] << " ";
//         for (auto vertex : graph[i]) {
//             cout << vertex.target << "," << vertex.weight << " ";
//         }
//         cout << endl;
//     }
// }

// Buscamos cual es el valor más pequeño del vector de cost que en la tabla de status tenga un valor de falso y obtnemos el índice correspondiente 
template<class T>
int Graph<T>::getSmallIndex(vector<bool> status, vector<int> cost) {
    // Creamos una variable con el valor menor que sea igual a infinito (minCost)
    int minCost = INT_MAX;
    // Creamos una variable para guardar cual fue el índice menor (minIndex) y la igualamos a -1
    int minIndex = -1;
    // Recorremos todos los valor del vector de status
    for (int i=0; i<size; i++) {
        // si el valor del indice actual del ciclo en el vector de status es igual a falso
        if (!status[i]) {
            // si es falso
            // validamos si el costo del indice atual es menor a minCost
            if (cost[i] < minCost) {
                // si es menor
                // cambiamos el valor de minCost por el costo del indice actual
                minCost = cost[i];
                // cambiamos el valor de minIndex por el índice actual
                minIndex = i;
            }
        }
    }
    // Regresar el valor de minIndex
    return minIndex;
}

template<class T>
void Graph<T>::Dijkstra(T vertex, T dest) {
    // Obtener el índice del vértice que recibimos de parámetro
    int index = findVertex(vertex);
    // Validar que si exista el vértice en la tabla de vértices
    if(index >=0){
        // Si existe
        // Inicializamos las tablas de trabajo
        // Creamos una vector del tamaño de size y la inicializamos en falso (status)
        vector<bool> status(size, false);
        // Creamos una vector del tamaño de size y la inicializamos con infinito (cost)
        vector<int> cost(size, INT_MAX);
        // Al valor del índice que corresponde al vértice inicial le asignamos 0
        cost[index] = 0;
        // Creamos una vector del tanaño de size y la inicializamos en -1
        vector<int> path(size,-1);
        // Creamos un varibale smallIndex y le asignamos el valor de la funcion getSmallIndex
        int smallIndex = getSmallIndex(status, cost);
        // Ciclo mientras smallIndex >= 0
        while(smallIndex >=0){
            // Actualizar el estado en el vector de status del smallIndex
            status[smallIndex] = true;
            // Recorremos todos los índice adyacentes del vertice con smallIndex
            for (auto adjVertex : graph[smallIndex]) {
                // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
                int adjIndex = findVertex(adjVertex.target);
                // Validamos que en el vector de status en adjIndex sea falso
                if(!status[adjIndex]){
                    // Si es Falso
                    // Validamos si el costo de adjIndex es mayor al costo de smallIndex + el peso del vértice adyacente
                    if (cost[adjIndex]>cost[smallIndex]+ adjVertex.weight)
                    {
                        // Si es mayor
                        // Cambiamos el costo de adjIndex al valor de la suma del costo de smallIndex + el peso del vértice adyacente
                        cost[adjIndex] =cost[smallIndex]+ adjVertex.weight;
                        // Cambiamos el valor del path de adjIndex por el valor de smallIndex
                        path[adjIndex] = smallIndex;
                    }else{
                    // else
                        // No es mayor
                        // Le seguimos con el siguiente vértice adyacente
                    }
                } else{
                // else
                    // No es Falso
                    // Le seguimos con el siguiente vértice adyacente
                }
            }
            // actualizams el valor de smallIndex con el valor de la funcion getSmallIndex
            smallIndex = getSmallIndex(status, cost);
        }
        // Aquí termina la primera parte del algoritmo
        // Empieza la segunda parte

        // Creamos un vector de pilas de números enteros del tamaño de size (pathStack) vetor< stack<int> > pathStack
        vector<stack<int>> pathStack(size);
        // Recorremos todos los vértices de mi tabla de vértices 
        for(int i=0; i < size; i++){
            // Validamos si el valor del vector cost en la posición del índice actual es < menor a infinito
            if(cost[i] < std::numeric_limits<int>::max()){
                // Si es menor
                // Insertar el índice actual en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(i))
                pathStack[i].push(i);
                // Creamos una variable para guardar el valor actual del path (pathIndex) pathIndex = i
                int pathIndex = i;
                // Ciclo mientras valor del vector path de la posición pathIndex != -1
                while(path[pathIndex]!=-1){
                    // insertar el valor que se encuentra en el vector path en la posición pathIndex en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(path[pathIndex]))
                    pathStack[i].push(path[pathIndex]);
                    // Actualizamos el valor de pathIndex con el valor del vector de path en la posición de pathIndex
                    pathIndex = path[pathIndex];
                }
            }
        }

        int sumWeight = 0;
        while (!pathStack[vertices.hashFunction(dest)].empty()) {
            cout << vertices[pathStack[vertices.hashFunction(dest)].top()] << " -> ";
            sumWeight = cost[pathStack[vertices.hashFunction(dest)].top()];
            pathStack[vertices.hashFunction(dest)].pop();
        }
        cout << "con un costo de:" << sumWeight << " mi"<< endl;

            
    } else{
    // else
        // No existe
        // Imprimir un error
        throw out_of_range("El vértice no se encuentra en el grafo");
    }
}

template<class T>
void Graph<T>::DijkstraReverse(T vertex, T dest) {
    // Obtener el índice del vértice que recibimos de parámetro
    int index = findVertex(vertex);
    // Validar que si exista el vértice en la tabla de vértices
    if(index >=0){
        // Si existe
        // Inicializamos las tablas de trabajo
        // Creamos una vector del tamaño de size y la inicializamos en falso (status)
        vector<bool> status(size, false);
        // Creamos una vector del tamaño de size y la inicializamos con infinito (cost)
        vector<int> cost(size, INT_MAX);
        // Al valor del índice que corresponde al vértice inicial le asignamos 0
        cost[index] = 0;
        // Creamos una vector del tanaño de size y la inicializamos en -1
        vector<int> path(size,-1);
        // Creamos un varibale smallIndex y le asignamos el valor de la funcion getSmallIndex
        int smallIndex = getSmallIndex(status, cost);
        // Ciclo mientras smallIndex >= 0
        while(smallIndex >=0){
            // Actualizar el estado en el vector de status del smallIndex
            status[smallIndex] = true;
            // Recorremos todos los índice adyacentes del vertice con smallIndex
            for (auto adjVertex : graph[smallIndex]) {
                // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
                int adjIndex = findVertex(adjVertex.target);
                // Validamos que en el vector de status en adjIndex sea falso
                if(!status[adjIndex]){
                    // Si es Falso
                    // Validamos si el costo de adjIndex es mayor al costo de smallIndex + el peso del vértice adyacente
                    if (cost[adjIndex]>(cost[smallIndex]+ adjVertex.weight*-1))
                    {
                        // Si es mayor
                        // Cambiamos el costo de adjIndex al valor de la suma del costo de smallIndex + el peso del vértice adyacente
                        cost[adjIndex] =cost[smallIndex]+ adjVertex.weight*-1;
                        // Cambiamos el valor del path de adjIndex por el valor de smallIndex
                        path[adjIndex] = smallIndex;
                    }else{
                    // else
                        // No es mayor
                        // Le seguimos con el siguiente vértice adyacente
                    }
                } else{
                // else
                    // No es Falso
                    // Le seguimos con el siguiente vértice adyacente
                }
            }
            // actualizams el valor de smallIndex con el valor de la funcion getSmallIndex
            smallIndex = getSmallIndex(status, cost);
        }
        // Aquí termina la primera parte del algoritmo
        // Empieza la segunda parte

        // Creamos un vector de pilas de números enteros del tamaño de size (pathStack) vetor< stack<int> > pathStack
        vector<stack<int>> pathStack(size);
        // Recorremos todos los vértices de mi tabla de vértices 
        for(int i=0; i < size; i++){
            // Validamos si el valor del vector cost en la posición del índice actual es < menor a infinito
            if(cost[i] < std::numeric_limits<int>::max()){
                // Si es menor
                // Insertar el índice actual en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(i))
                pathStack[i].push(i);
                // Creamos una variable para guardar el valor actual del path (pathIndex) pathIndex = i
                int pathIndex = i;
                // Ciclo mientras valor del vector path de la posición pathIndex != -1
                while(path[pathIndex]!=-1){
                    // insertar el valor que se encuentra en el vector path en la posición pathIndex en la pila en la posición del vector de pilas correspondiente al índice actual (pathStack[i].push(path[pathIndex]))
                    pathStack[i].push(path[pathIndex]);
                    // Actualizamos el valor de pathIndex con el valor del vector de path en la posición de pathIndex
                    pathIndex = path[pathIndex];
                }
            }
        }

        vector<string> unavailablePorts;

        for (int i=0; i<size; i++) {
            // imprimimos todos los elementos de la pila
            if (vertices[i] != "" && cost[i] == INT_MAX){
                    unavailablePorts.push_back(vertices[i]);
            }
        }

        
        int sumWeight = 0;
        while (!pathStack[vertices.hashFunction(dest)].empty()) {
            cout << vertices[pathStack[vertices.hashFunction(dest)].top()] << " -> ";
            sumWeight = cost[pathStack[vertices.hashFunction(dest)].top()];
            pathStack[vertices.hashFunction(dest)].pop();
        }
        cout << "con un costo de:" << -1*sumWeight << " mi"<< endl;

        if (unavailablePorts.size() == 0){
            cout << "Se pueden llegar a todos los puertos desde: " << vertex << "!" << endl;
        } else {
            cout << "No se pueden llegar a los siguientes puertos: ";
            for (auto port : unavailablePorts){
                cout << port << ", ";
            }
            cout << endl;
        }
        

        // // Imprimir todos los paths
        // for (int i=0; i<size; i++) {
        //     // imprimimos el vértice
        //     cout << vertices[i] << " ";
        //     // imprimimos todos los elementos de la pila
        //     while (!pathStack[i].empty()) {
        //         cout << pathStack[i].top() << " ";
        //         pathStack[i].pop();
        //     }
        //     cout << endl;
        // }


            
    } else{
    // else
        // No existe
        // Imprimir un error
        throw out_of_range("El vértice no se encuentra en el grafo");
    }
}

#endif