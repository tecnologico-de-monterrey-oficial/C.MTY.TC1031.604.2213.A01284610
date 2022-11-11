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

#endif