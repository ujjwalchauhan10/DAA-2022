/* Given an already sorted array of positive integers, design an algorithm and implement it using a
   program to find whether given key element is present in the array or not. Also, find total number
   of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input) */

// Recursion and iteration
#include <iostream>
using namespace std;
void it_binary_search(int[], int, int);
void rc_binary_search(int[], int, int, int, int);

int main()
{
    int n, key, h, l, op, c = 0;
    cout << "enter the number of element : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " element : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key element : ";
    cin >> key;
    h = n - 1;
    l = 0;
    cout << "1. iteration \n2. recursion" << endl;
    cin >> op;
    if (op == 1)                                  //Iteration
        it_binary_search(arr, key, n);
    else if (op == 2)                             //Recursion
        rc_binary_search(arr, h, l, key, c);
    else
        cout << "Wrong choice";
    return 0;
}

void it_binary_search(int arr[], int key, int n)
{
    int l = 0, t = n - 1, f = 0, temp, c = 0;
    do
    {
        c++;
        temp = (l + t) / 2;
        if (arr[temp] == key)
        {
            f = 1;
            cout << "Present " << temp + 1 << endl;
            break;
        }
        else if (arr[temp] > key)
        {
            t = temp - 1;
        }
        else
            l = temp + 1;
    } while (l != t);
    if (l == t)
    {
        cout << "Present at " << t << endl;
        c++;
        f = 1;
    }
    if (f == 0)
        cout << "Not present" << endl;
    cout << "total number of comparisons = " << c << endl;
}

void rc_binary_search(int arr[], int h, int l, int key, int c)
{
    int hh = h, ll = l;
    int mid = (hh + ll) / 2;
    c++;
    if (ll <= hh)
    {
        if (arr[mid] == key)
        {
            cout << "Present " << mid + 1 << endl;
            cout << "total number of comparisons = " << c << endl;
        }
        else if (key < arr[mid])
        {
            hh = mid - 1;
            rc_binary_search(arr, hh, ll, key, c);
        }
        else
        {
            ll = mid + 1;
            rc_binary_search(arr, hh, ll, key, c);
        }
    }
    else
    {
        cout << "Not Present" << endl;
    }
}