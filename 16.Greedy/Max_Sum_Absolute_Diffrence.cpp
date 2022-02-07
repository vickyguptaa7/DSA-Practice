#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int maxSum(int arr[], int n) // S.C -> O(n)
{
    sort(arr, arr + n);
    long long int sum = abs(arr[0] - arr[n - 1]) + abs(arr[0] - arr[n / 2]);
    for (int i = 1; i < n / 2; i++)
    {
        sum += abs(arr[i] - arr[n - 1 - i]);
        sum += abs(arr[i] - arr[n - i]);
    }
    if (n & 1)
        sum += abs(arr[n / 2] - arr[n / 2 + 1]);
    return sum;
}

int Max_Sum_Adjacent_Difference_Permutation(int arr[], int n) // S.C -> (N)
{
    sort(arr, arr + n);
    int Max = 0;
    vector<int> newarr;
    for (int i = 0, j = n - 1; i < n / 2; i++)
    {
        newarr.push_back(arr[i]);
        newarr.push_back(arr[j--]);
    }
    if (n & 1)
    {
        newarr.push_back(arr[n / 2]);
    }
    for (int i = 1; i < n; i++)
        Max += abs(newarr[i - 1] - newarr[i]);
    Max += abs(newarr[0] - newarr[n - 1]);

    return Max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Max_Sum_Adjacent_Difference_Permutation(arr, n) << endl;
    return 0;
}