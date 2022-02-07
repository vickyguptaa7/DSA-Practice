#include <iostream>
using namespace std;

bool Binary_Search(int arr[], int s, int n, int key)
{
    if (s>n)
    {
        return 0;
    }
    int m = s + (n - s) / 2;
    if (arr[m] == key)
    {
        return 1;
    }
    else if (arr[m] < key)
    {
        return Binary_Search(arr, m + 1, n, key);
    }
    else
    {
        return Binary_Search(arr, s, m - 1, key);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << Binary_Search(arr, 0, n - 1, key) << endl;
    return 0;
}