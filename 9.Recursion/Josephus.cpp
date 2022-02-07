#include <iostream>
using namespace std;

int Josephus(int arr[], int n, int k, int i = 0) //recursion
{
    if (n == 1)
    {
        return arr[0];
    }
    i = (i + k) % n;
    for (int j = i; j < n; j++)
    {
        arr[j] = arr[j + 1];
    }
    return Josephus(arr, n - 1, k, i);
}

int Josephus_Without_Recursion(int arr[], int n, int k)
{
    int i = 0;
    while (n != 1)
    {
        i = (i + k) % n;
        for (int j = i; j < n; j++)
        {
            arr[j] = arr[j + 1];
        }
        n--;
    }
    return arr[0];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    cout << Josephus_Without_Recursion(arr, n, k - 1) << endl;
    return 0;
}