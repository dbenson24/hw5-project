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

void sort2::sort(){
	// Shell sort on sortArray
	int gaps[8] = {701,301,132,57,23,10,4,1};
	for (int i=0; i<8; i++){
		gapinsertionsort(gaps[i]);
	}
}

void sort2::printArray(){
	// prints out the integers in sorted order
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}

void sort2::gapinsertionsort(int gap){
	for (int i = gap; i < sortArray.length; i++){
		int temp = sortArray.arr[i];
		int x;
		for (x = i; x >= gap && sortArray.arr[x-gap] > temp; x-=gap){
			sortArray.arr[x] = sortArray.arr[x-gap];
		}
		sortArray.arr[x] = temp;
	}
}


