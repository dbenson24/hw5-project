//
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm


#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
	sortArray.length = 0;
	sortArray.arr = NULL;
}

SelectionSort::~SelectionSort(){
	delete[] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
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

// selection sort on sortArray
void SelectionSort::sort(){
	// moves through each item on the array
	for (int i = 0; i < sortArray.length; i++){
		int min = i;
		// finds the smallest item still on the array
		for (int x = i; x < sortArray.length; x++){
			if (sortArray.arr[min] > sortArray.arr[x]){
				min = x;
			}
		}
		// moves the smallest item to the first unsorted spot
		swap(min, i);
	}
}

// prints out the integers in sorted order
void SelectionSort::printArray(){
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}

// swaps the elements at two given indices
// int a is the index of the first item
// int b is the index of the second item
void SelectionSort::swap(int a, int b){
	int temp = sortArray.arr[a];
	sortArray.arr[a]=sortArray.arr[b];
	sortArray.arr[b]=temp;
}

