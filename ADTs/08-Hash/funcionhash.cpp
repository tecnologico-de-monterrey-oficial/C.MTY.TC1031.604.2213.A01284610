#include <iostream>
using namespace std;

int hashFunction(string mat){
    int numMat = stoi(mat.substr(1,8));
    return numMat % 99;
}

int main(){
    cout << hashFunction("A01721732") << endl;
    return 0;
}