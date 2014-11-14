//
//  sort3.h
//  Header File for sort3 class
//

#ifndef __Sorting__MergeSort__
#define __Sorting__MergeSort__

#include <iostream>

struct arrayWithLength{
	int length;
	int *arr;
};

class sort3 {
public:
	sort3(); // constructor
	~sort3(); // destructor

	// read in a list of values from stdin
	void readList();

	// sort function
	void sort();

	// print the array
	void printArray();

private:
	arrayWithLength sortArray;

	// returns a sorted array from two smaller ones
	arrayWithLength merge(arrayWithLength l, arrayWithLength r);

	// returns a merge sorted array
	arrayWithLength mergeSort(arrayWithLength a);
};

#endif /* defined(__Sorting__MergeSort__) */

