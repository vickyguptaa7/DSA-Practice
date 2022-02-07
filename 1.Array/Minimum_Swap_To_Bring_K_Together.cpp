#include <iostream>
using namespace std;

int Swap_To_K(int arr[], int n, int k) //T.C - O(n^2)
{
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            z++;
        }
    }
    int Min = INT_MAX;
    for (int i = 0; i <= n - z; i++)
    {
        int count = 0;
        for (int j = i; j < i + z; j++)
        {
            if (arr[j] > k)
            {
                count++;
            }
        }
        Min = min(Min, count);
    }
    return Min;
}

int Swap_K(int arr[], int n, int m)
{
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= m)
        {
            z++;
        }
    }
    int count=0;
    for (int k = 0; k < z; k++)
    {
        if (arr[k] > m)
        {
            count++;
        }
    }

    int i = 0, j = z;
    int Min=count;
    while (j < n)
    {
        if(arr[i]>m)
        {
            count--;
        }
        if(arr[j]>m)
        {
            count++;
        }
        Min = min(Min, count);
        i++;
        j++;
        
    }
    return Min;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Swap_K(arr, n, m) << endl;

    return 0;
}