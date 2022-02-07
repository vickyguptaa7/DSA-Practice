#include <iostream>
using namespace std;

int Max_Subarray(int arr[],int n)
{
    int Sum=0,Min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        Sum+=arr[i];
        if(Sum>0)Sum=0;
        Min=min(Sum,Min);
    }
    Sum=0;
    for(int i=0;i<n;i++)
    {
        Sum+=arr[i];
    }
    return Sum-Min;   
}

int Max_Sum(int arr[], int n) // T.C O(n^2)
{
    int Max=0;
    for (int i = 0; i < n; i++)
    {
        int Sum = 0;
        for (int j = i; j < n; j++)
        {
            Sum += arr[j];
            if (Sum < 0)
                Sum = 0;

            Max = max(Sum, Max);
        }
        for (int j = 0; j < i; j++)
        {
            Sum += arr[j];
            if (Sum < 0)
                Sum = 0;

            Max = max(Sum, Max);
        }
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

    cout << Max_Subarray(arr, n) << endl;
    return 0;
}