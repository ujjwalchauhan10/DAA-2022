/*
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
For each test case, output will be “Present” if the key element is found in the array, otherwise 
“Not Present”.
*/

#include <iostream>
#include <cmath>
using namespace std;

class jumpsort{
    public:
    int jump_sort(int arr[], int n, int key){
        int jump = sqrt(n);
        int prev = 0;

        while(arr[min(jump,n)-1]<key)
        {
            prev = jump;
            jump += sqrt(n);
            if(prev >= n)
                return -1;
        }
        while(arr[prev]<key)
        {
            prev++;
            if(prev == min(jump,n))
                return-1;
        }

        if(arr[prev]==key)
        return prev;
    }
};

int main()
{
    jumpsort jp;
    int tc;
    cout<<"Enter the number of test cases : ";
    cin>>tc;
    while(tc>0)
    {
        int n, key;
        cout<<"Enter the number of element : ";
        cin>>n;
        int arr[n];
        cout<<"Enter the elements in array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Enter the key element : ";
        cin>>key;
        int f = jp.jump_sort(arr,n,key);
        if(f>n || f<0)
            cout<<"Not Present"<<endl;
        else
            cout<<"Present at "<<f<<endl;

        tc--;
    }
}