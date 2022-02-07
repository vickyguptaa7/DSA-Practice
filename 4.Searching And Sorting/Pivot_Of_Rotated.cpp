#include <iostream>
using namespace std;

int Pivot(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if(arr[mid]<arr[j])
        {
            j=mid;
        }
        else{
            i=mid+1;
        }
    }
    return arr[j];
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
    cout << Pivot(arr, n) << endl;

    return 0;
}