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
    int bigSon;
    while ((father * 2 + 1) < heap.size())
    {
        int son1 = father * 2 + 1;
        if ((father * 2 + 2) < heap.size())
        {
            int son2 = father * 2 + 2;
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
            father = heap.size(); 
        }
        else
        {

            swap(father, bigSon);
            father = bigSon;
        }
    }
}

template <class T>
Heap<T>::Heap(vector<T> list)
{
    heap = list;

    int father = (list.size() - 2) / 2;

    while (father >= 0)
    {
        downSort(father);
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list)
{
    heap = list;
    int father = (list.size() - 2) / 2;

    while (father >= 0)
    {
        downSort(father);
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