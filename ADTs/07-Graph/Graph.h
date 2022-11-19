#ifndef Graph_h
#define Graph_h

#include <queue>
#include "Vertex.h"

template<class T>
class Graph {
private:
    vector< vector< Vertex<T> > > graph;
    vector<T> vertices;
    int size;
    int findVertex(T vertex);
public:
    Graph();
    Graph(vector<T> vertices);
    Graph(vector<T> vertices, vector< Vertex<T> > edges);
    void addEdges(vector< Vertex<T> > edges);
    void addEdge(Vertex<T> edge);
    void addVertex(T vertex); // dejar pendiente
    void BFS(T vertex);
    void DFS(T Vertex); // Depth First Search
    void DFSR(int index, vector<bool> &status); 
    void print();
    void Dijkstra(T vertex);
};

// Constructor por default
template<class T>
Graph<T>::Graph() {
    size = 0;
}

// Constructor con lista de vertices
template<class T>
Graph<T>::Graph(vector<T> vertices) {
    this->vertices = vertices;
    size = vertices.size();
    // Cambiamos el tamaño de la matriz graph para almacenar todos los vertices
    graph.resize(size);
}

template<class T>
int Graph <T>::findVertex(T vertex) {
    typename vector<int>::iterator it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }     
}

template<class T>
Graph<T>::Graph(vector<T> vertices, vector< Vertex<T> > edges) {
    this->vertices = vertices;
    size = vertices.size();
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
void Graph<T>::BFS(T vertex) {
    // Creamos una vector del mismo tamaño del vector de vertices con valores boleanos inizializado en falso
    vector<bool> status(size, false);
    // Creamos una fila de tipo entero vacía
    queue<int> adjQueue;
    // Buscar el índice del vértice inicial (index)
    int index = findVertex(vertex);
    // validamos si existe
    if (index >= 0) {
        // si existe
        // agregamos el índice a la fila
        adjQueue.push(index);
        // cambiamos el estado del índice del vértice inicial en la lista de estados 
        status[index] = true;
        // Ciclo mientras la lista no este vacía
        while (!adjQueue.empty()) {
            // Obtenemos el elemento del principio de la fila
            index = adjQueue.front();
            // Imprimimos el nodo
            cout << vertices[index] << " ";
            // Recorremos todos los nodos adyacentes
            for (auto adjVertex : graph[index]) {
                // Buscamos el índice del nodo adyacente (adjIndex)
                int adjIndex = findVertex(adjVertex.target);
                // Revisamos el valor en la lista de estados de ese índice
                if (!status[adjIndex]) {
                    // si es falso
                    // agregamos el índice a la fila
                    adjQueue.push(adjIndex);
                    // cambiamos a verdado el valor de ese índice en la lista de estados
                    status[adjIndex] = true;
                }
            }
            // Sacamos el nodo de la fila
            adjQueue.pop();
        }
    }


}

template<class T>
void Graph<T>::DFS(T vertex){
    int index = findVertex(vertex);

    if (index >= 0){
        vector<bool> status(size,false);
        DFSR(index,status);
    }

}

template<class T>
void Graph<T>::DFSR(int index, vector<bool> &status){
    cout << vertices[index] << " ";

    status[index] = true;
    for (auto adj : graph[index]){
        int adjIndex = findVertex(adj.target);
        
        if (!status[adjIndex]){
            DFSR(adjIndex,status);
            cout << endl;
        }

    }
}

template<class T>
void Graph<T>::print() {
    for (int i=0; i<size; i++) {
        cout << vertices[i] << " ";
        for (auto vertex : graph[i]) {
            cout << vertex.target << "," << vertex.weight << " ";
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::Dijkstra(T vertex) {
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
        for(int i=0; i < vertices.size(); i++){
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
            
    } else{
    // else
        // No existe
        // Imprimir un error
        throw out_of_range("El vértice no se encuentra en el grafo");
    }
}

#endif