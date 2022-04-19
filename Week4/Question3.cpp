#include <iostream>
using namespace std;
 
int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1) {

        int pos = partition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) 
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
 
    return INT_MAX;
}
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 
int main()
{
    int t;
    cout << "Number of test cases : ";
    cin >> t;

    while (t > 0)
    {
    int n,k;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter value of k"<<endl;
    cin>>k;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
    t--;
    }
}