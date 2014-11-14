//
//  sort2.h
//  Header File for sort2 class
//

#ifndef __Sorting__ShellSort__
#define __Sorting__ShellSort__

#include <iostream>

struct arrayWithLength{
	int length;
	int *arr;
};

class sort2 {
public:
	sort2(); // constructor
	~sort2(); // destructor

	// read in a list of values from stdin
	void readList();

	// sort function
	void sort();

	// print the array
	void printArray();

private:
	arrayWithLength sortArray;

	// Gap sort the array
	void gapinsertionsort(int gap);
};

#endif /* defined(__Sorting__ShellSort__) */

