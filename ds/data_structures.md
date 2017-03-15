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

A stack can be implemented with an array or a linked list. Push and pop operations
can be completed in amortised constant time with either data structure, however a 
linked list implementation does not require dynamic resizing as an array 
implementation would.

## Queue
A queue is a First-in-First-out data structure. It has the following operations:
* Enqueue: add an element to the end of the queue
* Dequeue: remove the element at the front of the queue

Similarly to a stack, a queue can be implemented with either an array or a linked
list, and achieve amortized constant time enqueue and dequeue operations. 

### Priority Queue
A priority queue stores n integers and supports the following operations:
* Insert: adds a new integer
* Delete-min: removes the smallest integer and returns it



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
A undirected graph is a pair (V, E) where:
* V is a set of elements, each of which is called a node or vertex.
* E is a set of pairs (u, v) such that u and v are distinct nodes   
  and if (u, v) is in E then (v, u) is also in E.

A **path** is a sequence of nodes (v1, v2, ..., vk) such that for every
i in [1, k-1] there is an edge between vi and vi+1.

A **cycle** is a path such that v1 = vk and v1, v2, ..., vk-1 are distinct.

An undirected graph is **connected** if, for any two distinct verticies u and
v, there exists a path from u to v.


## Trees
A tree is a connected, undirected graph that contains no cycles. A tree with
n nodes will have n - 1 edges.

A **binary tree** is a tree where every node has at most 2 child nodes. This
can be generalised to a **k-ary tree** where each node has at most k child 
nodes.

A binary tree of height h is **complete** if:
* levels 0 to h - 2 are full
* at level h - 1, the leaf nodes are as far left as possible

A complete binary tree with n >= 2 nodes has height O(log n).

### Binary Heap
Let S be a set of n integers. A binary heap on S is a binary tree T satisfying:
* T is complete
* Every node u in T corresponds to a distinct integer in S (the integer is  
  called the key of u)
* If u is an internal node (not a leaf) the key of u is smaller than those of   
  its child nodes

Implementing insertion and deletion as described below allows the implementation
of a priority queue with O(log n) insertion and deletion. 

#### Insertion Algorithm
1. Create a leaf node z and put into T ensuring T remains complete
2. Set u to z
3. If u is the root, return
4. If the key of u is greater than the key of its parent p, return
5. Otherwise, swap the keys of u and p, set u to p then jump to step 3


#### Delete-Min Algorithm
1. Report the key of the root
2. Identify the rightmost leaf z at the bottom level of T
3. Delete z and store the key of z at the root
4. Set u to the root
5. If u is a leaf, return
6. If the key of u < the keys of its children, return
7. Otherwise, let v be the child of u with a smaller key. Swap the keys   
   of u and v, set u to v and repeat from step 5.

#### Finding the Rightmost Leaf
Inspecting the number of nodes (n) in binary, ignore the MSB. Then, scanning
the remaining bits from most to least significant, move left if the next bit 
is 0, otherwise move right.

#### Array Implementation
A complete binary tree can be stored in an array (linearized) such that:
* Nodes at a higher level appear before those at a lower level
* Within the same level, nodes are ordered from left to right

With this implementation, if u is stored at A[i] then the left child of
u is at A[2i] and the right child at A[2i + 1]. In this case, we also
know the parent of A[i] is stored at A[floor(i/2)].

A binary heap can be constructed from an array in O(n) time.
First, implement a root-fix operation as follows:
* Input: a binary tree with root r. It is guaranteed that:  
    * the left subtree of r is a binary heap
	* the right subtree of r is a binary heap
* Using the same method as described in delete-min, correct the binary heap
The binary heap can then be constructed with the following simple algorithm:
* For each i = n to 1:  
   * Perform root-fix on the subtree of T rooted at A[i]

### Binary Search Tree
A binary search tree enables a predecessor search, i.e. given an integer q,
return the largest value in a set that is less than or equal to q. A binary
search tree supports the following operations:
* Predecessor Query - in O(log n) time
* Insertion - in O(log n) time
* Deletion - in O(log n) time

In a binary search tree, it must hold that: the key of a node is larger than all
the keys in the left subtree of that node, and smaller than all the keys in the
right subtree. A given set can have a number of valid binary search tree representations.

In order to support O(log n) operations, a tree must be balanced. A binary tree is
**balanced** if the following holds for every internal node u:
* the height of the left subtree of u differs from that of the right subtree of u  
  by at most 1.

#### Predecessor Query Algorithm
Given a balanced BST T, a predecessor query can be answered with the following 
algorithm:
1. set p to negative infinity
2. set u to the root of T
3. If u is nil, return p
4. If the key of u is q, set p to q and return q
5. If the key of u is > q, set u to the left child and repeat from step 3
6. Otherwise, set p to the key of u and u to the right child, and repeat   
   from step 3.

A successor query can be performed with a slight modification to the above
algorithm.

#### AVL Tree
An AVL tree is a balanced binary search tree where every internal node u
stores the heights of its left and right subtrees. By storing the subtree
heights, an internal nodde knows whether it has become imbalanced.

A **2-level imbalance** occurs where:
* there is a difference of 2 in the heights of the left and right subtrees  
  of a node u
* all the proper descendants of u are balanced

In order to perform insertion and deletion, we need to be able to remedy a 
2-level imbalance. There are four cases: a left-left, left-right, right-left,
or right-right imbalance. A left-left or right-right imbalance can be remedied 
by changing only three pointers. A left-right or right-left imbalance can
be remedied by changing five pointers. (Better illustrated with pictures)...

##### Insertion
Insertion is performed by traversing the binary search tree as if we were
searching for the element we wish to insert. Once we hit a "dead end" (there
is no node in the direction we want to travel), we insert the node for the
element we are adding at that point. We then travel back up the tree, incrementing
the subtree height of each parent by 1. If an imbalance is detected, remedy
the imbalance at the lowest node.

##### Deletion
First, traverse the tree to find the node, u, that we wish to delete. 
* **Case 1:** If it is a leaf node, it can simply be deleted.
* **Case 2:** If u has a right subtree:
  1. Find the node v storing the successor s of e
  2. Set the key of u to s
  3. If v is a leaf node, remove it from the tree
  4. Otherwise, v must have a right child w which is a leaf.  
     Set the key of v to that of w and remove w from the tree.
* **Case 3:** If u hase no right subtree, it must hold that u has a  
  left child v, which is a leaf. Set the key of u to that of v and  
  remove v from the tree.

At this point, we have essentially descended a root-to-leaf path and
removed a leaf node. We now want to update subtree height values for
the nodes in this path in the bottom-up order. As in insertion, remedy
imbalances in a bottom-up order (however for deletions we may need to
remedy multiple imbalances).
At this point, we have essentially descended a root-to-leaf path and
removed a leaf node. We now want to update subtree height values for
the nodes in this path in the bottom-up order. As in insertion, remedy
imbalances in a bottom-up order (however for deletions we may need to
remedy multiple imbalances).


