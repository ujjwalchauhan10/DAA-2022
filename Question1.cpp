/*given an array of non negative integer, design a linear algo and implemet it using a program to
find wether given key element is present in the array or not also find total no. of comparision for
each inut case. Time complexcity O(n) where n is the size of input.
Sample input:-    no. of sample = 3
                  size of 1st input = 8
                  34 35 65 31 25 89 64 30
                  key = 89
                  5
                  977 354 244 546 355
                  key = 244
                  6
                  23 64 13 67 43 56
                  key = 63*/

#include <iostream>
using namespace std;
void check(int [], int, int);
int main()
{
    int i = 0, a;
    int n, key;
    cout << "Enter the number of sample : ";
    cin >> a;
    while (a != 0)
    {
        cout << "enter the number of element : ";
        cin >> n;
        int arr[n];
        cout << "Enter " << n << " element : "<<endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the key element : ";
        cin >> key;
        check(arr, n, key);
        a--;
    }
    return 0;
}
void check(int arr[], int n, int key)
{
    int f = 0, i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            f = 1;
            cout << "Present " << (i+1) << endl;
            break;
        }
    }
    if (f == 0)
        cout << "Not Present ";
}