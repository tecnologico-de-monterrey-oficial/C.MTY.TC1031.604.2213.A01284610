#include <iostream>
using namespace std;

#include "Node.h"

int main()
{
//Crear un apuntador a un espacio en memoria de tipo nodo
Node<int>* head;
head = new Node<int>(5);
//primer nodo
cout<<"Valor de head: "<<head<<endl;
cout<<"Valor de head->data:"<<head->data<<endl;
cout<<"Valor de head->next:"<<head->next<<endl;

head->next = new Node<int>(10);
//segundo nodo(primera opción)
cout<<"Primer nodo"<<endl;
cout<<"Valor de head: "<<head<<endl;
cout<<"Valor de head->data:"<<head->data<<endl;
cout<<"Valor de head->next:"<<head->next<<endl;

cout<<"Segundo nodo (primera opcion)"<<endl;
cout<<"Valor de head->next->data:"<<head->next->data<<endl;
cout<<"Valor de head->next->next:"<<head->next->next<<endl;

//Segunda opción
Node<int>* aux = head->next;

cout<<"Segundo nodo (segunda opcion)"<<endl;
cout<<"Valor de head->next->data:"<<head->next->data<<endl;
cout<<"Valor de head->next->next:"<<head->next->next<<endl;

    return 0;
}