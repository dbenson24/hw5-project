//
//  sort4.h
//  Header File for sort4 class
//

#ifndef __Sorting__QuickSort__
#define __Sorting__QuickSort__

#include <iostream>

struct arrayWithLength{
	int length;
	int *arr;
};

class sort4 {
public:
	sort4(); // constructor
	~sort4(); // deconstructor

	// read in a list of values from stdin
	void readList();

	// sort function
	void sort();

	// print the array
	void printArray();

private:
	arrayWithLength sortArray;

	// swaps values at a and b
	void swap(int a, int b);

	// sorts array from a to b
	void quickSort(int a, int b);

	// returns midpoint from a to b
	int findPivot(int a, int b);
};

#endif /* defined(__Sorting__QuickSort__) */

