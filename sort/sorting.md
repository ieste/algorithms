# Sorting Algorithms

The Sorting Problem can be defined as follows:

Given a set S of n integers in an array of length n, design an algorithm to store S in an array where
the elements have been arranged in ascending order.

## The Bad Algorithms

These are sorting algorithms with an average case O(n^2) time complexity. 
They include selection sort, insertion sort, bubble sort, and gnome sort.


### Selection Sort
1. Scan through the list to find the smallest element
2. Swap the smallest element with the first element
3. Repeat steps 1 and 2 on the sublist excluding the first element until the length of the list is 1

Selection sort will not benefit from the input array being sorted or mostly sorted, whereas the other
"bad" sorting algorithms will.


### Insertion Sort
1. For each element in the list
  1. While item to the left of element is greater
    1. Swap element with the one to its left

This algorithm effectively loops through each element in the list and inserts it into the correct position
in the sorted sublist to the left. In the algorithm listed above, a linear search is performed from 
right to left on the list to find the correct place to insert the element. Although a binary search
could be used, the need to shift the elements in the array before insertion means that this would not
improve the overall time complexity of the algorthm.


### Bubble Sort
1. For each pair of items (0, 1), (1, 2), ..., (n-2, n-1) in the list
  1. If the pair is in the wrong order, swap the items.
2. Repeat step 1 until no swaps are necessary

Bubble sort is typically very inefficient, even compared to the other "bad" algorithms.
It can be practical if the items in the list are already "almost" sorted, however.


## The Better Algorithms

All comparison-based sorting algorithms will have a lower bound of n log n (that is, it is impossible
to devise a comparison-based sorting algorithm with a better than n log n running time).

### Merge Sort
* Base Case:   
   When the problem size is 1 or 0, the array is already sorted
* Inductive Case:  
  1. Recursively sort the left half of the array
  2. Recursively sort the right half of the array
  3. Merge sorted left and right halves

Merging:
1. i = 0, j = 0
2. While i < len(L) and j < len(R)
  1. Append smaller of L[i] and R[j] to A
  2. Increment i if L[i] is smaller than R[j], otherwise increment j


### Quick Sort
* Base Case:
   When the problem size is 1, no further work needs to be done
* Inductive Case:
  1. Randomly pick an integer p in A called the pivot
  2. Rearrange the integers in A such that all integers smaller than p are before p and all integers larger than p are after
  3. Sort everything before p recursively
  4. Sort everything after p recursively

In the worst case this algorithm is no better than the "bad" algorithms, but it has an 
average case time complexity of O(n log n).
A common modification of this algorithm involves using selection sort once the problem size 
is below a certain level (say 5 items). 


### Heap Sort


## Non Comparison-Based Sorting Algorithms

The lower bound on time complexity of n log n can be overcome using algorithms that are
not comparison-based. 

### Counting Sort

### Radix Sort


