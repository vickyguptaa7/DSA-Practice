#include <iostream>
using namespace std;

int Count(int arr[], int s, int m, int n)
{
    int ic = 0;
    int p = m - s + 1, q = n - m;
    int arr1[p], arr2[q];
    for (int i = 0; i < p; i++)
        arr1[i] = arr[s + i];
    for (int i = 0; i < q; i++)
        arr2[i] = arr[m + 1 + i];

    int x = 0, y = 0, z = s;

    while (p > x && q > y)
    {
        if (arr1[x] > arr2[y])
        {
            arr[z] = arr2[y];
            ic += p - x;
            y++;
            z++;
        }
        else
        {
            arr[z] = arr1[x];
            x++;
            z++;
        }
    }
    while (p > x)
    {
        arr[z] = arr1[x];
        x++;
        z++;
    }
    while (q > y)
    {
        arr[z] = arr2[y];
        y++;
        z++;
    }
    return ic;
}

int Inversion_Count(int arr[], int s, int n)
{
    int ic = 0;
    if (s < n)
    {
        int mid = (s + n) / 2;
        ic += Inversion_Count(arr, s, mid);
        ic += Inversion_Count(arr, mid + 1, n);

        ic += Count(arr, s, mid, n);
    }
    return ic;
}

int main()
{
    int t,k=0;
    long long int arr1[t];
    cin >> t;
    while (t>k)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        arr1[k++]=Inversion_Count(arr, 0, n);
        delete[] arr;
    }
    for(int i=0;i<t;i++)
    cout<<endl<<endl<<arr1[i]<<endl<<endl;
    return 0;
}