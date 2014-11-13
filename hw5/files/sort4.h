//
//  sort4.h
//  Header File for sort4 class
//

#ifndef __Sorting__SelectionSort__
#define __Sorting__SelectionSort__

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
	void swap(int a, int b);
	void quickSort(int a, int b);
	int findPivot(int a, int b);
};

#endif /* defined(__Sorting__SelectionSort__) */

