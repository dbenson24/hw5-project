//
//  sort3.cpp
//  Sorts integers using the sort3 algorithm


#include "sort3.h"

using namespace std;

sort3::sort3(){ // constructor
	sortArray.length = 0;
	sortArray.arr = NULL;
}

sort3::~sort3(){ // destructor
	delete[] sortArray.arr;
}
// reads in a list of integers from stdin and returns an arrayWithLength
void sort3::readList(){
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

void sort3::sort(){
	// merge sort on sortArray
	arrayWithLength temp = mergeSort(sortArray);
	sortArray.arr = temp.arr;
}

void sort3::printArray(){
	// prints out the integers in sorted order
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}
arrayWithLength sort3::mergeSort(arrayWithLength a){
	if (a.length <= 1){
		return a;
	}

	arrayWithLength l;
	arrayWithLength r;
	int middle = a.length/2;
	l.arr = new int[middle];
	r.arr = new int[a.length-middle];
	l.length = 0;
	r.length = 0;
	for (int i=0; i<middle; i++){
		l.arr[i] = a.arr[i];
		l.length++;
	}
	for (int i = middle; i < a.length; i++){
		r.arr[i-middle] = a.arr[i];
		r.length++;
	}

	l=mergeSort(l);
	r=mergeSort(r);

	delete[] a.arr;
	return merge(l,r);
}
arrayWithLength sort3::merge(arrayWithLength l, arrayWithLength r){
	arrayWithLength a;
	a.length = l.length+r.length;
	a.arr = new int[a.length];
	int lpos = 0;
	int rpos = 0;
	int apos = 0;
	while (lpos < l.length || rpos < r.length){
		if (lpos < l.length && rpos < r.length){
			if (l.arr[lpos]<r.arr[rpos]){
				a.arr[apos] = l.arr[lpos];
				apos++;
				lpos++;
			}
			else{
				a.arr[apos] = r.arr[rpos];
				apos++;
				rpos++;
			}
		}
		else if (lpos < l.length){
			a.arr[apos] = l.arr[lpos];
			apos++;
			lpos++;
		}
		else if (rpos < r.length){
			a.arr[apos] = r.arr[rpos];
			apos++;
			rpos++;
		}
	}
	delete[] l.arr;
	delete[] r.arr;
	return a;
}


