# Data Structures

## Arrays
Arrays have a fixed length, making their use impractical when size of our data set
is dynamic. Re-allocating memory for the array and copying all elements to the 
new memory location would lead to a time complexity of O(n) for adding an
element to the end of an array. Instead we can double the size of the array each
time it runs out of space. This has an amortized cost of O(1) for adding an element
to the end of the array.
We can also halve the size of the array once its contents use less than a quarter
of the allocated space.


## Linked Lists
A linked list is an alternative to an array data structure that does not require
the contents be stored in contiguous memory. Each element in the list is a node,
which contains a pointer to the next node (as well as the previous node in the 
case of a doubly linked list). A reference to the head and tail of the list is
also stored.

A linked list supports insertion and deletion (given the pointer to the node at
which we want to insert or delete our element) in O(1) time. Insertion at an index
in the list requires traversing the list to find the ith element, so has a time
complexity of O(n).


## Stack
A stack is a First-in-Last-out data structure. It has the following operations:
* Push: add an element to the top of the stack
* Pop: remove the most recently added element from the stack

## Queue
A queue is a First-in-First-out data structure. It has the following operations:
* Enqueue: add an element to the end of the queue
* Dequeue: remove the element at the front of the queue

## Hash Table
The idea of hashing is to divide a dataset into *m* disjoint subsets such that only
one subset need be searched in order to answer a query. A hash function h(k)
maps any integer k to an integer in [1, m]. The value h(k) is called the hash value
of k.

A hash table solves the dictionary search problem, it has no concept of ordering
as a linked list or array does.

### Constructing the Table
A hash table is constructed as follows:
1. Create an array H of length m
2. For each i in [1, m], create an empty linked list and
   place the head and tail pointers of the list into H
3. For each integer x in our data set:
  1. Calculate the value h(x)
  2. Insert x into the list at H[h(x)]

Choosing an *m* in O(n) means this process has a time complexity of O(n).

### Querying the Table
To query a hash table for the value v, perform the following steps:
1. Calculate the hash value h(v)
2. Scan the list at H[h(v)] for v

In order to achieve an expected query time of O(1), it should have 
the **universal property**: the probability that the hash value of 
any two different integers is equal, is less than or equal to 1/m. 

The hand-wavy justification for this is that with this property we have 
n elements being divided into m = O(n) buckets approximately evenly,
resulting in n/O(n) = O(n/n) = O(1) items in each bucket. Querying
a list of length O(1) would take O(1) time.

### Designing a Hash Function
1. Pick a prime number *p* such that... 
  * *p* >= *m*, and 
  * *p* >= any possible integer *k*
2. Choose a number *a* uniformly at random from 1, ..., *p*-1
3. Choose a number *b* uniformly at random from 0, ..., *p*-1
4. Construct a hash function: h(*k*) = 1 + (((*ak* + *b*) mod *p*) mod *m*)


## Graphs

## Trees

