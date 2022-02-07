#include <iostream>
using namespace std;

void Merge(int *arr, int s, int m, int n)
{
    int p = m - s + 1;
    int q = n - m;
    int arr1[p];
    int arr2[q];

    for (int i = 0; i < p; i++)
    {
        arr1[i] = arr[i + s];
    }

    for (int i = 0; i < q; i++)
    {
        arr2[i] = arr[m + 1 + i];
    }

    int x = 0, y = 0, z = s;
    while (p > x && q > y)
    {
        if (arr1[x] > arr2[y])
        {
            arr[z] = arr2[y];
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
    while (p>x)
    {
        arr[z] = arr1[x];
        x++;
        z++;
    }

    while (q>y)
    {
        arr[z] = arr2[y];
        y++;
        z++;
    }
}

void Merge_Sort(int *arr, int s, int n)
{
    if (n > s)
    {
        int m = (n + s) / 2;
        Merge_Sort(arr, s, m);
        Merge_Sort(arr, m + 1, n);

        Merge(arr, s, m, n);
    }
}

int Binary_Search(int *arr,int n,int k)
{
    int i=0;
    while(n>i)
    {
        int Mid=(i+n)/2;
        if(arr[Mid]<k)
        {
            i=Mid++;
        }
        else if(arr[Mid]>k)
        {
            n=Mid--;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int Count_Equal_Pair(int *arr, int n, int k)
{
    Merge_Sort(arr, 0, n);
    int Count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp=k-arr[i];
        Count+=Binary_Search(arr,n,temp);
    }
    return Count;
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

    int k;
    cin >> k;

    // Merge_Sort(arr,0,n);

    cout << Count_Equal_Pair(arr, n, k) << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}