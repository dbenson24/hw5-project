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

void sort4::sort(){
	// quicksort on sortArray
	quickSort(0, sortArray.length);
}

void sort4::quickSort(int a, int b){
	if (a>=b){
		return;
	}
	int left = a+1;
	int right = b;
	int pivot = findPivot(a, b);
	int pivotvalue = sortArray.arr[pivot];
	swap(a, pivot);
	while (left!=right){
		if (sortArray.arr[left] < pivotvalue){
			left++;
		}
		if (sortArray.arr[right] > pivotvalue){
			right--;
		}
		if (sortArray.arr[left] > pivotvalue && sortArray.arr[right]){
			swap(left, right);
		}
	}
	swap(a, left);
	quickSort(a, left);
	quickSort(left+1, b);
	return;
}

void sort4::printArray(){
	// prints out the integers in sorted order
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}

void sort4::swap(int a, int b){
	int temp = sortArray.arr[a];
	sortArray.arr[a]=sortArray.arr[b];
	sortArray.arr[b]=temp;
}

int sort4::findPivot(int a, int b){
	return a + (b - a) / 2;
}

