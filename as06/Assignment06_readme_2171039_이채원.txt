# Code 1
- Introduction
This code sorts the given elements by heap sort.
First, it randomly generates data inside the heap, and inserts them. And, code builds max heap with build_max_heap function, and operates heap sort by taking off the elements from max heap. Since max heap pops out the element in decreasing order, the result of deletion would be in a sorted way. Finally, check_sort_results function checks that the result is sorted in increasing order, and prints whether it is or not. And, the time spent in sorting is also printed.
- How to run the code
You can just open this file with your IDE, and run it.
- How to adjust parameters
If you want to change the size of elements that would be sorted, you can change it with input_size variable.(line 121) And, the main code does not print the data inside the heap and the sorted result when the size of input is bigger than 20 in default, but if you want to change this, you can change it by modifying the value in line 138 and 150. 

# Code 2
- Introduction
This code encode characters by huffman coding, and operates the encoding and decoding process of given string.
First, it inserts the element and build a min heap with them. Then, with this heap, huffman_tree function generates huffman code. Then, huffman_traversal function recursively traveses the huffman tree and generates the huffman codeword of each characters. Finally, huffman_encoding and huffman_decoding function each encodes and decodes the given string with the huffam codeword generated above.
- How to run the code
You can just open this file with your IDE, and run it.
- How to adjust parameters
You can change the max length of heap, max bit of huffman codeword, and count of character from line 8 to line 10, and 48. If you want to change elements and each frequencies, you cna change it int line 301 and 302. Finally, if you want to change the string encoded and decoded by huffman coding, you can change it in line 331.

