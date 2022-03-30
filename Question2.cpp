#include <iostream>

using namespace std;

class selection_sort
{
public:
    void sel_sort(int arr[], int n)
    {
        int min,temp;
        for (int i = 0; i < n-1; i++)
        {
            min = i;
            for(int j=i; j<n; j++)
            {
                if(arr[j]<arr[min])
                {
                    min = j;
                }
            }
            temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    void show(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int T;
    cout << "Enter the number of test cases : ";
    cin >> T;
    while (T > 0)
    {
        int n;
        cout << "Enter the number of elements : ";
        cin >> n;
        int arr[n];
        cout<<"Enter the number : "<<endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        selection_sort obj;
        obj.sel_sort(arr, n);
        obj.show(arr, n);
        T--;
    }
    return 0;
}