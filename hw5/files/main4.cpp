//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "sort4.h"

using namespace std;

int main()
{
        sort3 sorter;
        cout << "array initialized";
        sorter.readList();
        cout << "List read";
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
