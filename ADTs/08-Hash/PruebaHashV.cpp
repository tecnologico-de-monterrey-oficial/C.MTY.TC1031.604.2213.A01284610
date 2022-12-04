#include <iostream>
#include <fstream>
using namespace std;

#include "HashMatV.h"

int main()
{
    HashMatV mat;
    fstream file("matriculas.txt");
    string matricula;
    while(file>>matricula){
        mat.addMatricula(matricula);
    }
    mat.print();

    return 0;
}