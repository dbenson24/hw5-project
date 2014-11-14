//
//  sort2.cpp
//  Sorts integers using the sort2 algorithm


#include "sort2.h"

using namespace std;

sort2::sort2(){ // constructor
	sortArray.length = 0;
	sortArray.arr = NULL;
}

sort2::~sort2(){ //destructor
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void sort2::readList(){
	int currentCapacity = 10;
	sortArray.arr = new int[currentCapacity];

	while (cin >> sortArray.arr[sortArray.length]) {
		++sortArray.length;
		if (sortArray.length==currentCapacity) {
			int *temp = new int[currentCapacity*2];
			for (int i=0;i<currentCapacity;i++) {
				temp[i] = sortArray.arr[i];
			}
			delete [] sortArray.arr;
			sortArray.arr = temp;
			currentCapacity *= 2;
		}
	}
}

// Shell sort on sortArray
void sort2::sort(){
	// Martin Ciura's Gap Sequence
	int gaps[8] = {701,301,132,57,23,10,4,1};

	for (int i=0; i<8; i++){
		// performs a gap sort with the determined gap
		gapinsertionsort(gaps[i]);
	}
}

// prints out the integers in sorted order
void sort2::printArray(){
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}

// performs a gap sort on the array
// int gap determines the gap size
void sort2::gapinsertionsort(int gap){
	// sorts every number separated by the gap using insertion sort
	for (int i = gap; i < sortArray.length; i++){
		int temp = sortArray.arr[i];
		int x;
		// counts down by the gap
		for (x = i; x >= gap && sortArray.arr[x-gap] > temp; x-=gap){
			sortArray.arr[x] = sortArray.arr[x-gap];
		}
		sortArray.arr[x] = temp;
	}
}


