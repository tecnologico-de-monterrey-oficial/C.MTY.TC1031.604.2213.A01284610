#include <iostream>
#include <vector>
using namespace std;

#include "Heap.h"

int main()
{
    // vector<int> list = {8,5,17,19,21,28};
    Heap<int> heap = {8,5,17,19,21,28};
    // Heap<int> heap(list);

    heap.print();

    return 0;
}