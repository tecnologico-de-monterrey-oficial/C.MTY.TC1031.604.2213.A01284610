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
    void append(T data);
    void print();
};

template<class T>
LinkedList<T>::LinkedList(){
    head nullptr;
    size = 0
}

template<class T>
void LinkedList<T>::append(T data){
    //encontrar ultimo
    //agregar nuevo a que apunte a null
    //apuntar el pasado ahora al nuevo
}


template<class T>
void LinkedList<T>::print(){
    //desde el head reccorer hasta que no sea null
}
#endif