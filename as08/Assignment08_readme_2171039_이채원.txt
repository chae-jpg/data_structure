# Code 1
- Introduction
This C program demonstrates the basic operations on a Min Heap, including decreasing a key, increasing a key, and deleting the minimum element. 

The program provides three main Min Heap operations:
# Decrease Key
The function `decrease_key_min_heap` decreases the key of a specified element in the Min Heap. It maintains the Min Heap property after the decrease.
# Increase Key
The function `increase_key_min_heap` increases the key of a specified element in the Min Heap. It maintains the Min Heap property after the increase.
# Delete Minimum
The function `delete_min_heap` deletes the minimum element from the Min Heap. It then reorganizes the heap to maintain the Min Heap property.

- How to Run the Code
You can just open the file in your ide, and run it.

- How to adjust parameters

If you want to work with a different set of initial heap elements or modify the key values in the operations, you can make the following adjustments:

# Modifying Initial Heap Elements
You can change the values in the array `{0, 1, 4, 2, 7, 5, 3, 3, 7, 8, 9}` to represent your own initial set of heap elements.

# Adjusting Key Values in Operations
You can modify the second and third parameters in these function calls to change the indices of elements and the key values in the operations.

# Code 2
- Introduction
This C program implements Prim's algorithm for finding the Minimum Spanning Tree (MST) of a graph with min heap. The graph is represented by the `weight` matrix, where `weight[i][j]` represents the weight of the edge between vertices `i` and `j`. The program uses a Min Heap to efficiently select the minimum-weight edge at each step.

- How to Run the Code
You can just open the file in your ide, and run it.

- How to adjust parameters
The graph is represented by the `weight` matrix. You can change the values in this matrix to represent your own graph. Note that `INF` represents infinity (indicating no edge).
