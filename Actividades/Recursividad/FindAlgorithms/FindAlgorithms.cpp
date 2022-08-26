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

bool sequentialSearch(vector<int> list, int n){
    for(int i = 0; i < list.size(); i++){
        if (list[i]==n){
            return true;
        }
    }
    return false;
}

template <class T>
bool binarySearch(vector<T> list, T value){
    //definir limite ing
    //definir limite suo
    //Iterar en la lista mientras limInf<=limSup
        //Calculo la poscion de en medio (liminf+limsup)/2
        //Comparar valor buscado es igual al valor en posicion en medio
            //si es igual
                //regresar verdadero
            //si no es igual
                //Revisar si el valor es MENOR al elemento en la posicion en medio
                    //Si es menor actualizar el limite superior con indice medio-1
                //Revisar si el valor es MAYOR al elemento en la posicion en medio
                    //Si es menor actualizar el limite inferior con indice medio+1
    //cuando me salgo del ciclo
    //regreso false

    int min = 0;
    int mid = 1;
    int max = list.size() - 1;

    while(min<=max){
        mid = (max+min)/2;
        if(list[mid]==value){
            //valor en index value
            return true;
        }
        if(list[mid]>value){
            max = mid - 1;
        } else if (list[mid]<value){
            min = mid + 1;
        }
    }
    //no existe
    return false;
}

int main()
{
    // Variables para calcular el tiempo de ejecución
    struct timeval begin, end;


    vector<int> list = {5,8,20,4,100,15};
    vector<int> list2 = {5,7,10,20,35,42,63,70,93,100};
    
    //solicita al usuario un nuemro entre el 1 y 100
    //despliega un mensaje que indique si el numero tecleado existe en la lista
    int userInput = 0;

    cout << "Ingrese el numero que quiera buscar: ";
    cin >> userInput;

    while (userInput > 100 || userInput < 1){
        cout << "Ingrese el numero que quiera buscar: ";
        cin >> userInput;
    }

    startTime(begin);
    if (sequentialSearch(list2, userInput)){
        cout << "Si existe sequencial" << endl;
    } else {
        cout << "no existe sequencial" << endl;
    }
    getTime(begin,end);

    startTime(begin);
    if (binarySearch(list2, userInput)){
        cout << "Si existe binario" << endl;
    } else {
        cout << "no existe binario" << endl;
    }
    getTime(begin,end);

    return 0;
}
