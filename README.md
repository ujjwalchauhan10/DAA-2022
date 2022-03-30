# DAA-2022
Design Analysis And Algorithms by Ujjwal Chauhan

Week 1:

Question 1. 
   Given an array of nonnegative integers, design a linear algorithm and implement it using a 
   program to find whether given key element is present in the array or not. Also, find total number 
   of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).
   
   
Question 2. 
   Given an already sorted array of positive integers, design an algorithm and implement it using a 
   program to find whether given key element is present in the array or not. Also, find total number 
   of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
   
   
Question 3. 
   Given an already sorted array of positive integers, design an algorithm and implement it using a
   program to find whether a given key element is present in the sorted array or not. For an array 
   arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval 
   (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to 
   find the element key. (Complexity < O(n), where n is the number of elements need to be scanned 
   for searching): Jump Search

   Input format: The first line contains number of test cases, T.
   For each test case, there will be three input lines.
   First line contains n (the size of array).
   Second line contains n space-separated integers describing array.
   Third line contains the key element that need to be searched in the array.

   Output format: The output will have T number of lines. 
   For each test case, output will be “Present” if the key element is found in the array, 
   otherwise “Not Present”.
