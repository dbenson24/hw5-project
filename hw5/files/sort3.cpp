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

// merge sort on sortArray
void sort3::sort(){
	arrayWithLength temp = mergeSort(sortArray);
	sortArray.arr = temp.arr;
}

// prints out the integers in sorted order
void sort3::printArray(){
	for (int i=0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << "\n";
}

// returns array sorted with mergeSort
// the arrayWithLength a is sorted
arrayWithLength sort3::mergeSort(arrayWithLength a){
	// if length is 1 or smaller it's already sorted
	if (a.length <= 1){
		return a;
	}

	// divides a into 2 smaller arrays
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

	// recursive call on the smaller arrays
	l=mergeSort(l);
	r=mergeSort(r);

	// prevent memory leaks now that new arrays exist
	delete[] a.arr;

	// return the sorted combination of the two
	// smaller arrays
	return merge(l,r);
}

// Merges two arrays to form a single sorted one
// arrayWithLength l is merged with arrayWithLength r
arrayWithLength sort3::merge(arrayWithLength l, arrayWithLength r){
	// creates larger array to store the combination
	arrayWithLength a;
	a.length = l.length+r.length;
	a.arr = new int[a.length];

	// keeps track of the latest index of each array
	int lpos = 0;
	int rpos = 0;
	int apos = 0;

	// loops through until l and r are empty
	while (lpos < l.length || rpos < r.length){
		// if both arrays still have numbers
		if (lpos < l.length && rpos < r.length){
			// the left is smaller than the right
			if (l.arr[lpos]<r.arr[rpos]){
				a.arr[apos] = l.arr[lpos];
				apos++;
				lpos++;
			}
			// the right is smaller than the left
			else{
				a.arr[apos] = r.arr[rpos];
				apos++;
				rpos++;
			}
		}
		// only the left has numbers left
		else if (lpos < l.length){
			a.arr[apos] = l.arr[lpos];
			apos++;
			lpos++;
		}
		// only the right has numbers left
		else if (rpos < r.length){
			a.arr[apos] = r.arr[rpos];
			apos++;
			rpos++;
		}
	}
	// delete the now useless arrays
	delete[] l.arr;
	delete[] r.arr;

	// return the larger sorted array
	return a;
}


