#ifndef Heap_h
#define Heap_h

template <class T>
class Heap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    void print();
};

template <class T>
Heap<T>::Heap()
{
}

template <class T>
void Heap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father)
{
    // Declaramos una variblae auxziliar para determinar el mayor de los hijos
    int bigSon;
    // ciclo para el reacomodo de cada padre (mientras el hijo menor sea menor al tamaño de la lista)
    while ((father * 2 + 1) < heap.size())
    {
        // Obtenemos cual de los hijos es el de mayor prioridad
        // creamos una variable con el valor del índice del primer hijo
        int son1 = father * 2 + 1;
        // Validamos si el auxFather tiene 2 hijos
        if ((father * 2 + 2) < heap.size())
        {
            // si tenie 2 hijos
            int son2 = father * 2 + 2;
            // Comparamos cual de los 2 hijos es mayor
            (heap[son1] > heap[son2]) ? bigSon = son1 : bigSon = son2;
        }
        else
        {
            // solo tiene 1 hijo
            bigSon = son1;
        }
        // comparamos el nodo padre con el hijo de mayor prioridad
        if (heap[father] > heap[bigSon])
        {
            // el nodo padre es de mayor prioridad que el mayor de los hijos
            // Se acaba el proceso de reacomodo para ese padre
            father = heap.size(); // para forzar que se salga del ciclo
        }
        // else
        else
        {
            // el nodo padre es de menor priridad que el mayo de los hijos
            // Intercambiamos el padre con el hijo de mayor prioridad
            swap(father, bigSon);
            // Volvemos al ciclo a hacer lo mismo con los hijos del hijo de mayor prioridad
            // Actualizamos auxFather igual a bigSon
            father = bigSon;
        }
    }
}

template <class T>
Heap<T>::Heap(vector<T> list)
{
    // copiar la lista actualizada al heap
    heap = list;
    // Encontrar cual es el primer nodo padre (((list.size()-1)-1)/2)
    int father = (list.size() - 2) / 2;
    // Recorremos todos los padres desde el primero de los padres hasta el nodo raíz
    // Recorrer desde el primer nodo padre hasta el nodo raíz
    while (father >= 0)
    {
        // Hacemos el downSort del father
        downSort(father);
        // Decrementamos el valor de father
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list)
{
    // copiar la lista actualizada al heap
    heap = list;
    // Encontrar cual es el primer nodo padre (((list.size()-1)-1)/2)
    int father = (list.size() - 2) / 2;
    // Recorremos todos los padres desde el primero de los padres hasta el nodo raíz
    // Recorrer desde el primer nodo padre hasta el nodo raíz
    while (father >= 0)
    {
        // Hacemos el downSort del father
        downSort(father);
        // Decrementamos el valor de father
        father--;
    }

}

template <class T>
void Heap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

#endif