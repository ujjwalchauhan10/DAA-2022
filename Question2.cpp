/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

Input format: The first line contains number of test cases, T. For each test case, there will be two
input lines. First line contains n (the size of array). Second line contains space-separated integers
describing array.

Output: The output will have T number of lines. For each test case T, print the value of i, j and k, if
found else print “No sequence found”.
*/

#include <iostream>
#include <vector>
using namespace std;
class sequence
{
public:
    vector<vector<int>> check_seq(vector<int> &arr, int n)
    {
        vector<vector<int>> seq;
        for (int i = 0; i < n - 2; i++)
        {
            int sum = 0;
            for (int j = i + 1; j < n - 1; j++)
            {
                sum = arr[i] + arr[j];
                for (int k = j + 1; k < n; k++)
                {
                    vector<int> c;
                    int f = 0;
                    if (sum == arr[k])
                    {
                        c.push_back(i);
                        c.push_back(j);
                        c.push_back(k);
                        f = 1;
                    }
                    if (f == 1)
                        seq.push_back(c);
                }
            }
        }
        return seq;
    }

    void show(vector<vector<int>> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int T;
    cout << "Enter number of test cases : ";
    cin >> T;
    while (T-- > 0)
    {
        int n, num;
        cout << "Enter the number of elements : ";
        cin >> n;
        vector<int> arr;
        cout << "Enter the numbers : " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            arr.push_back(num);
        }

        sequence s1;

        vector<vector<int>> vect = s1.check_seq(arr, n);
        s1.show(vect);

        /*
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                cout << vect[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
}