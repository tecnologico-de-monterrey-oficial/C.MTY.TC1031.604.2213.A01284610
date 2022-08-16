#include <iostream>
#include <vector>
using namespace std;

#include "List.h"

int sumInt(int n1, int n2, int n3){
    return n1 + n2 + n3;
}

double sumDouble(double n1, double n2, double n3){
    return n1 + n2 + n3;
}

float sumFloat(float n1, float n2, float n3){
    return n1 + n2 + n3;
}

string sumString(string a, string b, string c){
    return a + b + c;
}

template <class T>
T sumAnything(T a, T b, T c){
    return a+b+c;
}

int main() {
/*
    int a1 = 1;
    int b1 = 2;
    int c1 = 3;

    double a2 = 1.4;
    double b2 = 2.2;
    double c2 = 3.4;

    float a3 = 1.4;
    float b3 = 2.5;
    float c3 = 3.0;

    string a4 = "hola";
    string b4 = " crayola";
    string c4 = " mi cajita de colores";

    cout << "la suma de Integer a+b+c es igual a " << sumInt(a1,b1,c1) << endl;
    cout << "la suma Anything de a+b+c es igual a " << sumAnything(a1,b1,c1) << endl;

    cout << "\nla suma Double de a+b+c es igual a " << sumDouble(a2,b2,c2) << endl;
    cout << "la suma Anything de a+b+c es igual a " << sumAnything(a2,b2,c2) << endl;

    cout << "\nla suma Float de a+b+c es igual a " << sumFloat(a3,b3,c3) << endl;
    cout << "la suma Anything de a+b+c es igual a " << sumAnything(a3,b3,c3) << endl;

    cout << "\nla suma String de a+b+c es igual a " << sumString(a4,b4,c4) << endl;
    cout << "la suma Anything de a+b+c es igual a " << sumAnything(a4,b4,c4) << endl;
*/

    List< vector<int> > list;

    vector<int> list1 = {1,2,3,4,5};
    vector<int> list2 = {6,7,8,9,10};

    list.add(list1);
    list.add(list2);
    list.printVector();

  return 0;
}