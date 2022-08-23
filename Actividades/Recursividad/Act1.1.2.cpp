#include <iostream>

using namespace std;

int sumaImparIterativa(int arr[],int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if (arr[i]%2 == 1){
            sum += arr[i];
        }
    }
    return sum;
}

int sumaImparRecursiva(int arr[], int n){
    int sum = 0;
    if (n>0){
        if (arr[n-1]%2 == 1){
            sum = arr[n-1];
        }
        return sum + sumaImparRecursiva(arr,n-1);
    }
    return 0;
}

int main()
{
    int n = 5;
    int arr[5] = { 7, 3, 3, 5, 2};

    cout << "la suma es:" << endl;
    cout << sumaImparIterativa(arr,n) << endl;
    cout << sumaImparRecursiva(arr,n) << endl;
    return 0;
}
