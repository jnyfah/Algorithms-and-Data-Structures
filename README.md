# Data-Structures

Data structure is logical or mathematical organization of data; it describes how to store the data and access data from memory. There are two different types of data structure:   Linear Data Structure(sequential)e.g linked list and stacks     Non Linear Data Structure e.g trees and graphs

Linked List
        
        Stores data with nodes that point to other nodes.

Time Complexity:

    Indexing: Linked Lists: O(n)
    Search: Linked Lists: O(n)
    Optimized Search: Linked Lists: O(n)
    Insertion: Linked Lists: O(1)

Hash Table or Hash Map

    Stores data with key value pairs.
    Hash functions accept a key and return an output unique only to that specific key.
        
        Hash functions return a unique address in memory for that data.

    Hash collisions are when a hash function returns the same output for two distinct inputs. This can be solved 
    by using the seperate chaining or addressing meethod
        
Time Complexity:

    Indexing: Hash Tables: O(1)
    Search: Hash Tables: O(1)
    Insertion: Hash Tables: O(1)

Binary Tree
    
    Is a tree like data structure where every node has at most two children.
        There is one left and right child node.

Time Complexity:

    Indexing: Binary Search Tree: O(log n)
    Search: Binary Search Tree: O(log n)
    Insertion: Binary Search Tree: O(log n)



Efficient Sorting Basics
Merge Sort

    A comparison based sorting algorithm
        Divides entire dataset into groups of at most two.
        Compares each number one at a time, moving the smallest number to left of the pair.
        Once all pairs sorted it then compares left most elements of the two leftmost pairs creating a sorted group of four with the smallest numbers on the left and the largest ones on the right.
        This process is repeated until there is only one set.

Time Complexity:

    Best Case Sort: Merge Sort: O(n)
    Average Case Sort: Merge Sort: O(n log n)
    Worst Case Sort: Merge Sort: O(n log n)

Quicksort

    A comparison based sorting algorithm
        Divides entire dataset in half by selecting the middle element and putting all smaller elements to the left of the element and larger ones to the right.
        It repeats this process on the left side until it is comparing only two elements at which point the left side is sorted.
        When the left side is finished sorting it performs the same operation on the right side.
    Computer architecture favors the quicksort process.


Time Complexity:

    Best Case Sort: Merge Sort: O(n)
    Average Case Sort: Merge Sort: O(n log n)
    Worst Case Sort: Merge Sort: O(n^2)

Bubble Sort

    A comparison based sorting algorithm
        It iterates left to right comparing every couplet, moving the smaller element to the left.
        It repeats this process until it no longer moves an element to the left.

Time Complexity:

    Best Case Sort: Merge Sort: O(n)
    Average Case Sort: Merge Sort: O(n^2)
    Worst Case Sort: Merge Sort: O(n^2)
