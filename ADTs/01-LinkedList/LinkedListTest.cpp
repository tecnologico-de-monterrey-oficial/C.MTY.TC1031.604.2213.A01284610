#include <iostream>
using namespace std;

#include "LinkedList.h"
int main()
{
    LinkedList<string> list;
    list.appendRight("a");
    list.print();
    cout << "ok" << endl;
    list.appendRight("b");
    list.appendRight("c");
    list.appendRight("d");
    list.appendRight("e");
    list.appendLeft("Y");
    list.print();
    cout << "ok" << endl;
    list.deleteAt(3);
    list.print();
    cout << "ok" << endl;
    cout << list.findData("Y") << endl;
    cout << list.findData("b") << endl;
    cout << list.findData("e") << endl;
    cout << list.findData("ß") << endl;
    cout << "ok" << endl;
    cout << list.getData(2) << endl;
    cout << "ok" << endl;
    cout << list[0] << endl;
    cout << list[4] << endl;


    return 0;
}