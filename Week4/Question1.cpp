#include <iostream>

using namespace std;

class merge
{
    int c = 0;

public:
    void merge_sort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            merge_sort(arr, l, mid);
            merge_sort(arr, mid + 1, r);

            merge_sub(arr, l, mid, r);
        }
    }

    void merge_sub(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] < R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];    
            c++;
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];
    }

    int inverse(int arr[], int n)
    {
        int ci = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] > arr[j])
                    ci++;
        return ci;
    }

    void show(int arr[], int n, int count)
    {
        cout << endl;
        cout << "Sorted array : " << endl;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "Compartsion = " << c << endl;
        cout << "Inversions = " << count << endl;

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
        int n;
        cout << "Enter the number of elements in array : ";
        cin >> n;

        int arr[n];

        cout << "enter the elements in array : " << endl;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        merge obj;
        int count = obj.inverse(arr, n);
        obj.merge_sort(arr, 0, n);
        obj.show(arr, n, count);
        t--;
    }
}