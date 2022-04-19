#include <iostream>
using namespace std;

void merge(int[], int, int, int);
void merge_sort(int[], int, int);

class two_element
{
    int brr[100];
    int n = 0;

public:
    void check(int arr[], int n, int key)
    {
        for (int i = 0; i < n - 1; i++)
            binary_search(arr, i + 1, n, key, i);
    }

    int binary_search(int arr[], int l, int r, int key, int i)
    {
        if (r >= l)
        {

            int mid = l + (r - l) / 2;
            if ((arr[mid] + arr[i]) == key)
            {
                brr[n++] = arr[mid];
                brr[n++] = arr[i];
            }
            else if ((arr[mid] + arr[i]) > key)
            {
                binary_search(arr, l, mid - 1, key, i);
            }
            else
            {
                binary_search(arr, mid + 1, r, key, i);
            }
        }
    }

    void show()
    {
        for (int i = 0; i < n; i = i + 2)
            cout << brr[i] << " , " << brr[i + 1] << endl;
        cout << endl;
    }
};

int main()
{
    int t;
    cout << "Enter number of test cases : ";
    cin >> t;

    while (t > 0)
    {
        int n, key;

        cout << "Enter the number of elements : ";
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Enter the key : ";
        cin >> key;

        merge_sort(arr, 0, n);

        two_element obj;
        obj.check(arr, n, key);
        obj.show();
        t--;
    }
    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}