#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeSum(int arr[], int n, int k)
{
    sort(arr, arr + n);
    if (arr[0] < 0)
    {
        int i;
        for (i = 0; i < k && i < n; i++)
        {
            if (arr[i] < 0)
                arr[i] = -arr[i];
            else
                break;
        }
        if (i != k)
        {
            int j = k - i;
            if (i == n)
                i--;
            if (j & 1)
                arr[i] = -arr[i];
        }
    }
    else
    {
        if (k & 1)
        {
            arr[0] = -arr[0];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maximizeSum(arr,n,k)<<endl;
    return 0;
}