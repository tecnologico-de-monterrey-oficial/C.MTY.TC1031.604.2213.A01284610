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
void LinkedList<T>::print(){
    Node<T>* aux = head;
    int x = 1;
    while (aux-> next != nullptr)
    {
        cout << "dato " x << ": " << aux->data << endl;
        x++;
        aux = aux -> next;
    }
    
    cout << "dato " x << ": " << aux->data << endl;
}
#endif