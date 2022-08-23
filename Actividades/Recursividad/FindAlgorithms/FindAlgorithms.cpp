#include <iostream>
#include <vector>

using namespace std;

bool sequentialSearch(vector<int> list, int n){
    for(int i = 0; i < list.size(); i++){
        if (list[i]==n){
            return true;
        }
    }
    return false;
}

template <class T>
bool binarySearch(vector<T>, T value){
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


                
}

int main()
{
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

    if (sequentialSearch(list, userInput)){
        cout << "Si existe";
    } else {
        cout << "no existe";
    }

    return 0;
}
