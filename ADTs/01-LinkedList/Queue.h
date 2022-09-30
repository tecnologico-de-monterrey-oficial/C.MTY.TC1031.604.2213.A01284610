#ifndef Queue_h
#define Queue_h

#include "Node.h"

template<class T>
class Queue {
private:
    Node<T>* head;
    int size;

public:
    Queue(); //done
    T pop();
    void push(T data); //done
    T peak(); //done
    void print(); //done
    bool isEmpty(); //done
};

template<class T>
Queue<T>::Queue(){
    head = nullptr;
    size = 0;
}

template<class T>
void Queue<T>::push(T data){
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
T Queue<T>::peak() {
    return head->data;
}

template<class T>
T Queue<T>::pop() {
    if(head == nullptr){
        return;
    } else {
        Node<T>* temp = head;
        T toReturn = temp->data;
        head = head->next;
        delete temp;
        return toReturn;
    }
}

template<class T>
void Queue<T>::print(){
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
bool Queue<T>::isEmpty() {
    return size == 0;
}

#endif