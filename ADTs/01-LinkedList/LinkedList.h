#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList();
    void appendRight(T data); //done
    void appendLeft(T data); //done
    int findData(T data); //done
    T getData(int index); //done
    T operator[](int index); //done
    void insert(int index, T data); //done
    void deleteAt(int index); //done
    void deleteData (T data);
    void print(); //done
    bool isEmpty(); //done
};

template<class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

template<class T>
void LinkedList<T>::appendRight(T data){
    if(head == nullptr){
        head = new Node<T>(data);
        this->size++;
    } else {
        Node<T>* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new Node<T>(data);
        this->size++;
    }

    //encontrar ultimo
    //agregar nuevo a que apunte a null
    //apuntar el pasado ahora al nuevo
}

template<class T>
void LinkedList<T>::appendLeft(T data){

    Node<T>* aux = head;
    head = new Node<T>(data, head);
    this->size++;

}

template<class T>
int LinkedList<T>::findData(T data){
    if(head == nullptr){
        return -1;
    } else {
        Node<T>* temp = head;
        int index = 0;
        while(temp->next!=nullptr){
            if (temp->data == data){
                return index;
            }
            index++;
            temp = temp->next;
        }
        
        if (temp->data == data){
            return index;
        } else {
            return -1;
        }
    }
}

template<class T>
T LinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

template<class T>
T LinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

template<class T>
void LinkedList<T>::insert(int index, T data) {
    // Nos aseguramos que el índice que nos mandaron sea valído
    if (index >= 0 && index < size) {
        // Creamos un apuntador Aux que apunte a Head
        Node<T>* aux = head;
        // Crear un índice auxiliar igual a 0 para saber en que posición de la lista vamos 
        int auxIndex = 0;
        // Recorremos la lista hasta encontrar el índice dado
        while (auxIndex < index) {
            // Incrementar en 1 el valor del índice auxiliar
            auxIndex++;
            // Recorrer Aux
            aux = aux->next;
        }
        // Al salir del ciclo Aux apunta al nodo del indice dado
        // Insertar el nodo nuevo despues de AUX
        // Voy a apuntar el nodo nuevo a donde apuntaba aux
        aux->next = new Node<T>(data, aux->next);
        // Incrementamos en 1 el tamaño de la lista
        size++;
    // No es valido
    } else {
        // Generar una excepción
        throw out_of_range("El índice es inválido");
    }
}

template<class T>
void LinkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        size--;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

template<class T>
void LinkedList<T>::deleteData(T data) {
    deleteAt(findData(data));
}


template<class T>
void LinkedList<T>::print(){
    Node<T>* aux = head;
    int x = 1;
    while (aux-> next != nullptr)
    {
        cout << "dato " << x << ": " << aux->data << endl;
        x++;
        aux = aux -> next;
    }
    
    cout << "dato " << x << ": " << aux->data << endl;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

#endif