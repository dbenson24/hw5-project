//
//  sort3.h
//  Header File for sort3 class
//

#ifndef __Sorting__SelectionSort__
#define __Sorting__SelectionSort__

#include <iostream>

struct arrayWithLength{
	int length;
	int *arr;
};

class sort3 {
public:
	sort3(); // constructor
	~sort3();

	// read in a list of values from stdin
	void readList();

	// sort function
	void sort();

	// print the array
	void printArray();

private:
	arrayWithLength sortArray;
	arrayWithLength merge(arrayWithLength l, arrayWithLength r);
	arrayWithLength mergeSort(arrayWithLength a);
};

#endif /* defined(__Sorting__SelectionSort__) */

