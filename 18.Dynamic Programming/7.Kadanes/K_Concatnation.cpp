#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Largest_Sum_Subarray(int arr[], int n)
{
    int max_sum = arr[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        if (max_sum < sum)
            max_sum = sum;
    }

    return max_sum;
}

int K_Concatnation_Max_Sum_Subarray(int arr[], int n, int k)
{
    if (k == 1)
    {
        return Largest_Sum_Subarray(arr, n);
    }

    int max_sum = arr[0], sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        sum += arr[i % n];
        if (max_sum < sum)
            max_sum = sum;
        if (sum < 0)
            sum = 0;
    }
    sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum < 0)
    {
        return max_sum;
    }
    else
    {
        return max_sum + (k - 2) * sum;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << K_Concatnation_Max_Sum_Subarray(arr, n, k) << "\n";
    return 0;
}