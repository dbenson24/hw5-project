//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "SelectionSort.h"

using namespace std;

int main()
{
        SelectionSort sorter;
        cout << "array initialized";
        sorter.readList();
        cout << "List read";
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
