#include <iostream>
using namespace std;

#include "Queue.h"

int main()
{
    Queue<int> Qu;    

    Qu.push(40);
    Qu.push(20);    
    Qu.push(60); 
    Qu.push(10);
    Qu.push(30);
    Qu.push(15);   
    Qu.push(25);
    Qu.push(12);
    Qu.print();
    cout << Qu.peak() << endl;
    Qu.pop();

    Qu.print();
    return 0;
}