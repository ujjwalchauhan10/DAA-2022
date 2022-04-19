#include <iostream>
using namespace std;

class quickSort
{
    int comp_count=0;
    int swap_count=0;
public:
    void quick_sort(int arr[], int l, int r)
    {

        if (l < r)
        {
            int p = partition(arr, l, r);
            quick_sort(arr, l, p - 1);
            quick_sort(arr, p + 1, r);
        }
    }
    int partition(int arr[], int l, int r)
    {
        int x = rand() % (r - l + 1) + l;
        swap(&arr[x], &arr[r]);

        int pivot = arr[r];
        int i = (l - 1);
        for (int j = l; j <= (r - l); j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
            comp_count++;
        }
        swap(&arr[i + 1], &arr[r]);
        return (i + 1);
    }
    void swap(int *a, int *b)
    {
        swap_count++;
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void show(int arr[], int n)
    {
        cout << endl;
        cout << "Sorted array : " << endl;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "Compartsion = " << comp_count << endl;
        cout << "Swaps = " << swap_count << endl;

        cout << endl;
    }
};

int main()
{
    int t;
    cout << "Number of test cases : ";
    cin >> t;

    while (t > 0)
    {
        int n;
        cout << "Enter number of elements : ";
        cin >> n;

        int arr[n];

        cout << "Enter the numbers : " << endl;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        quickSort obj;
        obj.quick_sort(arr, 0, n - 1);
        obj.show(arr,n);
        t--;
    }
}