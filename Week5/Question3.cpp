#include <iostream>
using namespace std;

void combine(int L[], int n1, int R[], int n2)
{
    int i = 0, j = 0;
    while (i < n1 || j < n2)
    {
        if (L[i] == R[j])
        {
            cout << L[i] << " ";
            i++;
            j++;
        }
        else if (L[i] < R[j])
            i++;
        else
            j++;
    }
}

int main()
{
    int t;
    cout << "Enter the test cases : ";
    cin >> t;

    while (t > 0)
    {
    int n, m;

    cout << "Enter size of 1st array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter size of 2nd array : ";
    cin >> m;
    int brr[m];
    cout << "Enter the elements : " << endl;
    for (int j = 0; j < m; j++)
        cin >> brr[j];

    combine(arr, n, brr, m);
    t--;
    }
}
