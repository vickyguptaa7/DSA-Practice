#include <iostream>
using namespace std;

int Product(int arr[], int n)
{
    int Max = 1;
    int tmax = 1, tmin = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            tmax = 1;
            tmin = 1;
        }
        else if (arr[i] > 0)
        {
            tmax *= arr[i];
            tmin = min(tmin * arr[i], tmin);
        }
        else
        {
            int temp=tmax;
            tmax=tmin;
            tmin=temp;
            tmin *= arr[i];
            tmax = max(tmax * arr[i], tmax);
        }
        Max=max(tmax,Max);
    }    
    return Max;
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

    cout << Product(arr, n) << endl;
    return 0;
}