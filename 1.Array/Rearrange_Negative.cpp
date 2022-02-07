#include <iostream>
using namespace std;

void Swap(int *arr, int n, int j, bool Chk)
{
    int temp = 0;

    for (int i = j + 1; i < n; i++)
    {
        if (Chk)
        {
            if (arr[i] >= 0)
            {
                temp = i;
                break;
            }
        }
        else
        {
            if (arr[i] < 0)
            {
                temp = i;
                break;
            }
        }
    }
    if (temp != 0)
        for (int i = temp; i > j; i--)
        {
            int use = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = use;
        }
}

void Rearrange(int *arr, int n) // T.C O(n^2) And Space Complexity O(1)
{
    for (int i = 0; i < n; i++)
    {
        bool Chk = true;
        if ((i % 2 == 0) && arr[i] > 0)
        {
            Chk = false;
            Swap(arr, n, i, Chk);
        }
        else if (i % 2 == 1 && arr[i] < 0)
        {
            Swap(arr, n, i, Chk);
        }
    }
}

void swap(int *arr, int i, int k)
{
    int temp = arr[i];
    arr[i] = arr[k];
    arr[k] = temp;
}

void Rearge(int *arr, int n) // T.C - O(n) S.C - O(1) But Order Changes
{
    int i = 0, k = n - 1;
    while (i < k)
    {
        if (arr[i] < 0 && arr[k] >= 0)
        {
            swap(arr,i,k);
            k--;
            i++;
        }
        else if (arr[i] >= 0)
        {
            i++;
        }
        else if (arr[k] <= 0)
        {
            k--;
        }
    }
    i=0;k=n-1;
    while(i<k)
    {
        if(i%2==0)
        {
            swap(arr,i,k);
            i++;k--;
        }
        else
        {
            i++;
        }
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

    Rearge(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}