/*
Given an unsorted array of positive integers, design an algorithm and implement it
using a program to find whether there are any duplicate elements in the array or not.
(use sorting) (Time Complexity = O(n log n))

Input Format: The first line contains number of test cases, T. For each test case, there
will be two input lines. First line contains n (the size of array). Second line contains
space-separated integers describing array.

Output Format: The output will have T number of lines. For each test case, output will
be 'YES' if duplicates are present otherwise ‘NO’.
*/

#include <iostream>
using namespace std;

int duplicate(int[], int);
void show(int);

int main()
{
    int T;
    cout << "Enter number of test cases : ";
    cin >> T;

    while (T-- > 0)
    {
        int n;
        cout << "Enter the number elements : ";
        
        cin >> n;
        int arr[n];

        cout<<"Enter the element : "<<endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int dp = duplicate(arr, n);
        show(dp);
    }
}

int duplicate(int arr[], int n)
{
    int f = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i]==arr[j])
            {
                f=1;
            }
        }
        if(f==1)
           break;
    }
    return f;
}

void show(int dp)
{
    if(dp == 1)
       cout<<"YES"<<endl;
    else
       cout<<"NO"<<endl;
}