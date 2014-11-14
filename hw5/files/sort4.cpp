//
//  sort4.cpp
//  Sorts integers using the sort4 algorithm


#include "sort4.h"

using namespace std;

sort4::sort4(){ // constructor
	sortArray.length = 0;
	sortArray.arr = NULL;
}

sort4::~sort4(){
	delete[] sortArray.arr;
}
// reads in a list of integers from stdin and returns an arrayWithLength
void sort4::readList(){
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

// quicksort on sortArray
void sort4::sort(){
	quickSort(0, sortArray.length-1);
}

// performs a quickSort on the array between a and b
// int a is the low index and int b is the high index
void sort4::quickSort(int a, int b){
	// makes sure index a is below index b
	if (a>=b){
		return;
	}
	int left = a;
	int right = b;
	int pivot = findPivot(a, b);
	int pivotvalue = sortArray.arr[pivot];
	// moves the left and right indices towards each other
	// until they meet at the same point.
	while (left <= right){
		// moves left to next switchable value
		while (sortArray.arr[left] < pivotvalue){
			left++;
		}
		// moves right to next switchable value
		while (sortArray.arr[right] > pivotvalue){
			right--;
		}
		// swap left and right once they reach that value
		if (left <= right){
			swap(left, right);
			left++;
			right--;
		}
	}
	// recursive calls if there are still numbers
	// to be sorted
	if (a < right)
		quickSort(a, right);
	if (left < b)
		quickSort(left, b);
	return;
}

// prints out the integers in sorted order
void sort4::printArray(){
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}

// swaps the elements at two given indices
// int a is the index of the first item
// int b is the index of the second item
void sort4::swap(int a, int b){
	int temp = sortArray.arr[a];
	sortArray.arr[a]=sortArray.arr[b];
	sortArray.arr[b]=temp;
}

// finds the pivot, midpoint on the sequence
// int a is the starting point of the sequence
// int b is the ending point of the sequence
int sort4::findPivot(int a, int b){
	return a + (b - a) / 2;
}


