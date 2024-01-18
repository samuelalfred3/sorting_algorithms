- 0x1B. C - Sorting algorithms & Big O

* General
What is the Big O notation, and how to evaluate the time complexity of an algorithm
How to select the best sorting algorithm for a given input
What is a stable sorting algorithm

* Requirements
* General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called sort.h
Don’t forget to push your header file
All your header files should be include guarded
A list/array does not need to be sorted if its size is less than 2.

* The "C - Sorting algorithms & Big O" Topic with examples.

* Bubble Sort:

- Time Complexity:
Worst Case: O(n^2)
Average Case: O(n^2)
Best Case: O(n)
-Description: Bubble Sort compares adjacent elements and swaps them if they are in the wrong order. This process is repeated until the entire list is sorted.

* Merge Sort:

- Time Complexity:
Worst Case: O(n log n)
Average Case: O(n log n)
Best Case: O(n log n)
-Description: Merge Sort uses a divide-and-conquer approach. It divides the list into two halves, recursively sorts each half, and then merges them back together to create a sorted list.

* Quick Sort:

- Time Complexity:
Worst Case: O(n^2) (rare, but possible)
Average Case: O(n log n)
Best Case: O(n log n)
- Description: Quick Sort also employs divide-and-conquer. It selects a pivot, partitions the list based on the pivot, and recursively sorts the sublists. It is generally efficient and widely used.

* Insertion Sort:

- Time Complexity:
Worst Case: O(n^2)
Average Case: O(n^2)
Best Case: O(n)
- Description: Insertion Sort builds the final sorted array one element at a time. It is efficient for small lists or nearly sorted lists.

* Big O Notation:

- Big O notation is used to describe the upper bound of the algorithm's time complexity in the worst-case scenario.
- Examples:
O(1): Constant time complexity (e.g., accessing an element in an array).
O(log n): Logarithmic time complexity (e.g., binary search).
O(n): Linear time complexity (e.g., linear search).
O(n log n): Linearithmic time complexity (e.g., efficient sorting algorithms like Merge Sort and Quick Sort).
O(n^2): Quadratic time complexity (e.g., Bubble Sort, Insertion Sort).
