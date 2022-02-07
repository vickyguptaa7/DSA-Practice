#include <iostream>
using namespace std;

int Trapped_Water(int arr[], int n) // T.C - O(n^2) & S.C - O(1)
{
    int trap=0;
    for (int i = 1; i < n - 1; i++)
    {
        int Lmax = arr[i], Rmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            Lmax = max(Lmax, arr[j]);
        }
        for (int j = i + 1; j < n; j++)
        {
            Rmax = max(Rmax, arr[j]);
        }
        trap += min(Lmax, Rmax) - arr[i];
    }
    return trap;
}

int Trap_Water(int arr[],int n) // T.C - O(n) & S.C - O(n)
{
    int Lmax[n],Max=0;
    
    for(int i=0;i<n;i++)
    {
        Max=max(arr[i],Max);
        Lmax[i]=Max;
    }

    int Rmax[n];
    Max=0;
    
    for(int i=n-1;i>=0;i--)
    {
        Max=max(arr[i],Max);
        Rmax[i]=Max;
    }
    int Trap=0;
    for(int i=0;i<n;i++)
    {
        int Min=min(Lmax[i],Rmax[i]);
        Trap+=Min-arr[i];
    }
    return Trap;
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
    int trap = Trap_Water(arr,n);

    cout << trap << endl;
    return 0;
}