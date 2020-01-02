# Priority-Queues

This repository contains the code for three different implementations of a Priority Queue: unsorted, sorted, and heap. 
Every entry in each Priority Queue consists of a <key, value> pair. The key is an integer and determines the priority of the entry. Keys that are greater result in higher priority entries. 

When an entry is popped from the Priority Queue, it will be the entry with the highest priority key, not the value.

By pushing a number of entries, and then popping every entry in the Priority Queue, the resulting entries will be sorted from greatest to lowest priority. 
By pushing and popping each version of Priority Queue will act as a sorting algorithm:
--------------------------------------------------------------------------------------
The Unsorted PQ will show a version of selection sort. O(n^2)
The Sorted PQ will show a version of insertion sort. O(n^2)
The Heap PQ will show a version of Heap sort. O(nlog n)

Operations:
-----------
### Unsorted: ###
  - empty O(1)
  - size O(1)
  - push O(1)
  - pop O(n)
  - top O(n)
  - print
