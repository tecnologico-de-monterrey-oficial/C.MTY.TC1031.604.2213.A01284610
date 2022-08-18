#include <iostream>
using namespace std;

//metodo menu
void menu(){
    cout << "\n\n====[MENU]====" << endl;
    cout << "[1] fibonacci" << endl;
    cout << "[2] bacteria" << endl;
    cout << "[3] inversion" << endl;
    cout << "[4] potencia" << endl;
    cout << "[0] terminar" << endl;
}


//metodos fibonacci
int fibonaccIterativo(int n){
    int result;
    int temp1 = 1;
    int temp2 = 1;
    if (n > 2){
        for (int i = 2; i < n; i++){
            result = temp1 + temp2;
            temp1 = temp2;
            temp2 = result;
        }
    } else {
        return 1;
    }
    return result;
}

int fibonacciRecursivo(int n){
    if (n > 2){
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    } else {
        return 1;
    }
}

//metodos bacteria
double bacteriaIterativa(double n){
    double result = 1;
    for (int i = 0; i < n; i++){
        result *= (3.78-2.34);
    }
    return result;
}

double bacteriaRecursiva(double n){
    if (n > 0){
        return bacteriaRecursiva(n-1)*(3.78-2.34);
    } else {
        return 1;
    }
}

//metodos inversion
double inversionIterativa(double n, double montoInicial){
    for (int i = 0; i < n; i++){
        montoInicial = montoInicial*1.1875;
    }
    return montoInicial;
}

double inversionRecursiva(double n, double montoInicial){
    if (n > 0){
        return inversionRecursiva(n-1,montoInicial)*(1.1875);
    } else {
        return montoInicial;
    }
}

//metodos potencia
int potenciaIterativa(int n, int exp){
    if (exp == 0)
    return 1;

    int factor = n;
    for (int i = 1; i < exp; i++){
        n = n*factor;
    }
    return n;
}

int potenciaRecursiva(int n, int exp){
    if (exp == 0)
    return 1;

    if (exp > 1){
        return n * potenciaRecursiva(n,exp-1);
    } else {
        return n;
    }
}




int main() {

    int opcion = 0;
    bool loop = true;
    double number = 0;
    double number2 = 0;

    while(loop){
            menu();
            cout << "Ingrese la funcion que quiere: ";
            cin >> opcion;

        switch (opcion){
            case 1:
                cout << "\nIngrese el numero de secuencia para el programa fibonacci: ";
                cin >> number;
                cout << "\nMetodo Iterativo: " << fibonaccIterativo(number) << endl;
                cout << "Metodo Recursivo: " << fibonacciRecursivo(number) << endl;
            break;
            case 2:
                cout << "\nIngrese el numero de días para el programa bacteria: ";
                cin >> number;
                cout << "\nMetodo Iterativo: " << (int)bacteriaIterativa(number) << endl;
                cout << "Metodo Recursivo: " << (int)bacteriaRecursiva(number) << endl;
            break;
            case 3:
                cout << "\nIngrese el numero de meses para el programa inversion: ";
                cin >> number;
                cout << "\nIngrese el monto inicial para el programa inversion: ";
                cin >> number2;
                cout << "\nMetodo Iterativo: " << inversionIterativa(number,number2) << endl;
                cout << "Metodo Recursivo: " << inversionRecursiva(number,number2) << endl;
            break;
            case 4:
                cout << "\nIngrese la base para el programa potencia: ";
                cin >> number;
                cout << "\nIngrese el exponente para el programa potencia: ";
                cin >> number2;
                cout << "Metodo Iterativo: " << potenciaIterativa(number, number2) << endl;
                cout << "Metodo Recursivo: " << potenciaRecursiva(number, number2) << endl;
            break;
            case 0:
                cout << "Muchas Gracias!" << endl;
                loop = false;
            break;
            default:
                cout << "Hubo un error. ";
            break;
        }
    }

  return 0;
}