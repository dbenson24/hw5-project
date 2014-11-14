# ReadMe for COMP 15 HW5
## Sorting Assignment 
### Derek Benson

* Grading Note: I did a total of four sorts and modified the make file to
  compile and provide them.

This program provides four different options for sorting arrays of integers
with lengths. Selection sort uses a selection sort, sort2 is a shell sort,
sort3 is a merge sort, and sort4 is a quick sort. 

main1.cpp 
    Provides some basic test code for a selection sort. Reads in data from
    a txt file and sorts it.

SelectionSort.cpp 
    Defines the selection sort class. Used to perform a selection sort
    on an arraywithlength. 

SelectionSort.h 
    This is the header file for the SelectionSort class. It declares
    all of the methods and variables defined in SelectionSort.cpp.

main2.cpp 
    Provides some basic test code for a shell sort. Reads in data from
    a txt file and sorts it.

sort2.cpp 
    Defines the sort2 class. Used to perform a shell sort on an
    arraywithlength.

sort2.h 
    This is the header file for the sort2 class. It declares
    all of the methods and variables defined in sort2.cpp.

main3.cpp 
    Provides some basic test code for a merge sort. Reads in data from
    a txt file and sorts it.

sort3.cpp 
    Defines the sort3 class. Used to perform a merge sort on an
    arraywithlength.

sort3.h
    This is the header file for the sort3 class. It declares
    all of the methods and variables defined in sort3.cpp.

main4.cpp 
    Provides some basic test code for a quicksort. Reads in data from
    a txt file and sorts it.

sort4.cpp 
    Defines the sort4 class. Used to perform a quicksort on an
    arraywithlength.

sort4.h
    This is the header file for the sort4. It declares
    all of the methods and variables defined in sort4.cpp.


		---- Sorting Algorithms ----


Selection Sort:
    Loops through the array placing the smallest item in the remaining
    portion of the array at the front.

Shell Sort:
    Sorts the array based on gap intervals that decrease until they
    equal to 1. It is similar to bubble sorting except with gaps.

Merge Sort:
    Breaks the array into halves until each piece is only 1 item large.
    These small arrays are then merged together so that the large array
    ends up being fully sorted.

Quicksort:
    First a pivot is chosen, it is the midpoint on the array. Numbers 
    that are larger than the pivot are moved to the right of the pivot.
    Numbers that are smaller than the pivot are moved to the left of the
    pivot. The array on either side of the pivot is then recursively sorted.

