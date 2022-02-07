#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Largest_Sum_Subarray_Brute(int arr[], int n)
{
    int max_sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (max_sum < sum)
                max_sum = sum;
        }
    }
    return max_sum;
}

int Largest_Sum_Subarray_Better(int arr[], int n)
{
    int max_sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (max_sum < sum)
                max_sum = sum;
        }
    }

    return max_sum;
}

int Largest_Sum_Subarray_Opt(int arr[], int n)
{
    int max_sum = arr[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max_sum < sum)
            max_sum = sum;
        if (sum < 0)
            sum = 0;
    }

    return max_sum;
}

int Minimum_Sum_Subarray_Opt(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = -arr[i];
    int max_sum = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max_sum < sum)
            max_sum = sum;
        if (sum < 0)
            sum = 0;
    }
    for (int i = 0; i < n; i++)
        arr[i] = -arr[i];
    return -max_sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Largest_Sum_Subarray_Brute(arr, n) << "\n";
    cout << Largest_Sum_Subarray_Better(arr, n) << "\n";
    cout << Largest_Sum_Subarray_Opt(arr, n) << "\n";
    cout << Minimum_Sum_Subarray_Opt(arr, n) << "\n";
    return 0;
}