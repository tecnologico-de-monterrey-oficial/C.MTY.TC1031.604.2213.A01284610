#ifndef BST_H
#define BST_H

#include "NodeT.h"

template<class T>
class BST {
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* aux, int level);
public:
    BST();
    void insert(T data);
    bool find(T data);
    void remove(T data);
    void print();
    bool isEmpty();
};

template<class T>
BST<T>::BST() {
    root = nullptr;
}

template<class T>
void BST<T>::insert(T data) {
    // Validamos si el arbol está vacío
    if (isEmpty()) {
        // Si esta vació
        // Apuntamos root a un nuevo nodo con el valor de data
        root = new NodeT<T>(data);
    // else
    } else {
        // Si no está vacío
        // Creamos un nodo auxiliar igual a root
        NodeT<T>* aux = root;
        // Recorremos el arbol hasta encontrar donde colocar el nodo nuevo (while aux != nullptr)
        while (aux != nullptr) {
            // Comparamos si data es menor el valor del nodo auxiliar
            if (data < aux->data) {
                // Si es menor
                // Revisamos si el apuntador left de aux es igual a nulo
                if (aux->left == nullptr) {
                    // si es nulo
                    // Creamos un nuevo nodo en el apuntador del lado izquierdo de aux
                    aux->left = new NodeT<T>(data);
                    // Nos salimos de la función
                    return;
                // else
                } else {
                    // Si no es nulo
                    // Recorremos aux al hijo del lado izquierdo de aux
                    aux = aux->left;
                }
            // else 
            } else {
                // No es menor
                // Revisamos si el apuntador right de aux es igual a nulo
                if (aux->right == nullptr) {
                    // si es nulo
                    // Creamos un nuevo nodo en el apuntador del lado derecho de aux
                    aux->right = new NodeT<T>(data);
                    // Nos salimos de la función
                    return;
                // else
                } else {
                    // Si no es nulo
                    // Recorremos aux al hijo del lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template<class T>
bool BST<T>::find(T data) {
    // Creamos un nodo auxiliar igual a root
    NodeT<T>* aux = root;
    // Recorremos el arbol mientras aux sea diferente de nulos
    while (aux != nullptr) {
        // Validamos si el valor buscado es igual al valor de aux
        if (aux->data == data) {
            // Si son iguales
            // YA LO ENCONTRAMOS y regresamos true
            return true;
        // else 
        } else {
            // No son iguales
            // Validamos si el valor buscado es menor que el valor de aux
            if (data < aux->data) {
                // Si es menor
                // Recorremos aux al apuntador del lado izquierdo de aux
                aux = aux->left;
            // else
            } else {
                // No es menor
                // Recorremos aux al apuntador del lado derecho de aux
                aux = aux->right;
            }   
        }
    }
    // cuando nos salimos del ciclo, quiere decir que no lo encontramos
    // NO LO ENCONTRAMOS y regresamos falso
    return false;
}

template<class T>
void BST<T>::remove(T data) {
    // Validar si el arbol no esta vacío
    // Encontrarlo
    NodeT<T>* aux = root;
    NodeT<T>* prev = nullptr;

    bool found = false;

    while (aux != nullptr) {
        // Validamos si el valor buscado es igual al valor de aux
        if (aux->data == data) {
            // Si son iguales
            // YA LO ENCONTRAMOS y regresamos true
            found = true;
        // else 
        } else {
            // No son iguales
            // Validamos si el valor buscado es menor que el valor de aux
            if (data < aux->data) {
                // Si es menor
                // Recorremos aux al apuntador del lado izquierdo de aux
                prev = aux;
                aux = aux->left;
            // else
            } else {
                // No es menor
                // Recorremos aux al apuntador del lado derecho de aux
                prev = aux;
                aux = aux->right;
            }   
        }
    }

    if (found){

        //has 0 or 1 child
        if (aux->left == nullptr || aux->right == nullptr){
            NodeT<T>* holder;
            if (aux->left == NULL){
                holder = aux->right;
            } else {
                holder = aux->left;
            }

            if (aux == prev->left){
                prev->left = holder;
            } else{
                prev->right = holder;
            }
            free(aux);
        } else {
            //has 2 children
            NodeT<T>* temp;
            NodeT<T>* prev2 = nullptr;

            temp = aux->left;
            while (temp->right != NULL) {
            prev2 = temp;
            temp = temp->right;
            }

            if (prev2 != NULL)
                prev2->right = temp->left;
    
            else
                curr->left = temp->left;
    
            curr->data = temp->data;
            free(temp);
        }

    }



    // Validar cuantos hijos tiene el nodo a borar
        // No tiene hijos
            // El apuntador del papa del lado donde encontré el valor a eliminar va a apuntar a nulos
        // Tiene 1 hijo
            // El apuntador del papa del lado donde encontré el valor a eliminar va a apuntar al hijo
        // Tiene 2 hijos
            // Buscar el hijo más grande del lado izquierdo del nodo a eliminar
            // Movemos el valor del nodo más grande del lado izquierdo al valor del nodo a eliminar
            // Eliminamos el nodo más grande del lado izquierdo
                // Solo puede ser sin hijos o con 1 hijo (Mandar llamar a la función de borrar)

}

template<class T>
void BST<T>::printTree(NodeT<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}
#endif