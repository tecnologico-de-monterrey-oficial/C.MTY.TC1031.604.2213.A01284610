#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(struct timeval &begin)
{
  // start time
  gettimeofday(&begin, 0);
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(struct timeval begin, struct timeval end)
{
  long seconds, microseconds;
  double elapsed;
  // end time
  gettimeofday(&end, 0);
  seconds = end.tv_sec - begin.tv_sec;
  microseconds = end.tv_usec - begin.tv_usec;
  elapsed = seconds + microseconds * 1e-6;
  printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}

// Búsqueda Secuencial (O(n))
template <class T>
bool sequentialSearch(vector<T> list, T value) {
    // Algoritmo de búsqueda secuencial
    // Iteramos en todos los elementos de la list con un for de 0 al tamaño de la lisrta
    /*for (int i=0; i<list.size(); i++) {
        // Validamos si el valor de n es igual al elemento i de la lista
        if (list[i] == n) {
            return true;
        }
    }
    */
    for (auto el : list) {
        if (el == value) {
            return true;
        }
    }
    return false;
}

// Búsqueda Binaria (O log2(n))
template <class T>
bool binarySearch(vector<T> list, T value) {
    // Definir el límite inferior
    int left = 0;
    // Definir el límite superior
    int right = list.size() - 1;
    // Iterar en la lista mientras el límite inferior <= limite superior
    while (left <= right) {
        // Calculo la posición del índice de en medio (limite inferior + limite superior) / 2
        int mid = (left + right) / 2;
        // Reviso si el valor búscado es igual el elemento de la posición del índice de en medio
        if (list[mid] == value) {
            // Si es igual
            // Regreso verdadero
            return true;
        } else {
            // Si no es igual
            // Reviso si valor buscado es menor al elemento de la posición del índice de en medio
            if (value < list[mid]) {
                // Si es menor
                // actualizo el límite superior con el valor del índice de en medio - 1
                right = mid -1;
            } else {
                // Si es mayor
                // actualizo el límite inferior con el valor del índice de en medio + 1
                left = mid + 1;
            }
        }
    }
    // Cuando me salga del ciclo
    // Regreso falso
    return false;
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

void createListChar(vector<char> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = 91;
    while (num >= 91 && num <= 96)
    {
      num = rand() % 58 + 65;
    }
    list.push_back(char(num));
  }
}

template <class T>
void swapSort(vector<T> &list, int &swaps, int &comparisons){

  for(int i = 0; i<list.size();i++){
    for(int j = i+1; j-list.size();j++){
      comparisons++;
      if (list [i] > list[j]){
        swaps++;
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }

}

template <class T>
void bubbleSort(vector<T> &list, int &swaps, int &comparisons){

  for(int i = list.size()-1; i>0;i--){
    bool swapped = false;
    for(int j = 0; j<i;j++){
      comparisons++;
      if (list [j] > list[j+1]){
        swaps++;
        swapped = true;
        T temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
    if(!swapped)
      return;
  }

}

template <class T>
void selectionSort(vector<T> &list, int &swaps, int &comparisons){

  int min;
  for(int i = 0; i<list.size()-1;i++){

    int minIndex = i;
    for(int j = i+1; j<list.size();j++){
      comparisons++;
      if (list [j] < list[minIndex]){
        minIndex = j;
      }
    }
    if (minIndex!=i){
      swaps++;
      T temp = list[minIndex];
      list[minIndex] = list[i];
      list[i] = temp;
    }
  }
}

template <class T>
void insertionSort(vector<T> &list, int &swaps, int &comparisons){

  for(int i = 1; i < list.size();i++){
    T temp = list[i];
    int j = i-1;
    comparisons++;
    while(j>=0 && list[j]>temp){
      swaps++;
      comparisons++;
      list[j+1] = list[j];
      j--;
    }
    list[j+1] = temp;
  }

}

template <class T>
void printVector(vector<T> list){
  for(int i = 0; i<list.size();i++){
      cout << list[i] << " ";
    }
  cout << endl;
}

int main()
{
  // Variables para calcular el tiempo de ejecución
  struct timeval begin, end;

  vector<int> list;
  int swaps = 0;
  int comparisons = 0;

  createListInt(list,10);
  vector<int> listDup = list;
  
  printVector(list);
  cout << "\n Swap Sort:" << endl;
  list = listDup;
  swaps = 0;
  comparisons = 0;
  startTime(begin);
  swapSort(list, swaps, comparisons);
  getTime(begin,end);
  cout << "Comparaciones: " << comparisons << "\tIntercambios: " << swaps << endl;
  printVector(list);

  cout << "\n Bubble Sort:" << endl;
  list = listDup;
  swaps = 0;
  comparisons = 0;
  startTime(begin);
  bubbleSort(list, swaps, comparisons);
  getTime(begin,end);
  cout << "Comparaciones: " << comparisons << "\tIntercambios: " << swaps << endl;
  printVector(list);

  cout << "\n Selection Sort:" << endl;
  list = listDup;
  swaps = 0;
  comparisons = 0;
  startTime(begin);
  selectionSort(list, swaps, comparisons);
  getTime(begin,end);
  cout << "Comparaciones: " << comparisons << "\tIntercambios: " << swaps << endl;
  printVector(list);

  cout << "\n Insetrion Sort:" << endl;
  list = listDup;
  swaps = 0;
  comparisons = 0;
  startTime(begin);
  insertionSort(list, swaps, comparisons);
  getTime(begin,end);
  cout << "Comparaciones: " << comparisons << "\tIntercambios: " << swaps << endl;
  printVector(list);

  
  return 0;
}