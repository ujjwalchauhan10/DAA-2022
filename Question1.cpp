#include <iostream>
using namespace std;

int check(int[], int, int, int);
int c=0;
int main()
{
    int op;
    cout << "Enter the total number of test cases : ";
    cin >> op;
    while (op > 0)
    {
        c=0;
        int n, key, l = 0, h;
        cout << "Enter the number of elements : ";
        cin >> n;
        h = n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the key element : ";
        cin >> key;
        check(arr, key, l, h);
        op--;
        cout<<key<<" - "<<c<<endl;
    }
}
int check(int arr[], int key, int l, int h)
{
    int mid = (l + h) / 2;
    if (arr[mid] == key && l<=h)
    {
        c++;
    }
    if (l < h)
    {
        check(arr, key, mid + 1, h);
        check(arr, key, l, mid - 1);
    }
}