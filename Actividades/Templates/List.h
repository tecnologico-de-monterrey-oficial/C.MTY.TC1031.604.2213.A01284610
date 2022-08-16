#ifndef List_h
#define List_h

template <class T>
class List {
    private:
    vector<T> list;
    int size;

    public:
    List();
    List(vector<T> list);
    void add(T a);
    void print();
    void printVector();
};

// Contructor por default
template <class T>
List<T>::List(){
    //inicializar el tamaño de la lista
    size = 0;
    cout << "Constructor por default" << endl;
}

// Contructor con parametros default
template <class T>
List<T>::List(vector<T> list){
    this->list = list;
    size = list.size();
    cout << "Constructor con parametros" << endl;
}

//agrega elemento a la lista
template <class T>
void List<T>::add(T a){
    list.push_back(a);
    size++;
}

// Imprimir lista
// for (int i; i < size; i++) {
//      cout << list[i] << endl;
// }
template <class T>
void List<T>::print(){
    for (auto el : list){
        cout << el << endl;
    }
}

template <class T>
void List<T>::printVector(){
    for (auto el : list){
        for (auto l : el){
            cout << l << endl;
        }
    cout << endl;
    }
}

#endif