//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "sort2.h"

using namespace std;

int main()
{
        sort2 sorter;
        cout << "array initialized";
        sorter.readList();
        cout << "List read";
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
