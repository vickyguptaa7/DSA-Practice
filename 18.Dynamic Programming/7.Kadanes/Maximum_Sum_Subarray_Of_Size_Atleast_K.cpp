#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Sum_Subarray_Atleast_K_Size(int arr[], int n, int k)
{
    int largest_sum[n], sum = arr[0];
    largest_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (sum > 0)
            sum += arr[i];
        else
            sum = arr[i];

        largest_sum[i] = sum;
    }
    int K_Exactly = 0, K_More = 0;
    for (int i = 0; i < k; i++)
        K_Exactly += arr[i];
    int ans = INT_MIN;
    ans = max(ans, K_Exactly);
    for (int i = k; i < n; i++)
    {
        K_Exactly += arr[i] - arr[i - k];
        if (K_Exactly > ans)
            ans = K_Exactly;
        K_More = K_Exactly + largest_sum[i - k];
        if (K_More > ans)
            ans = K_More;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Max_Sum_Subarray_Atleast_K_Size(arr, n, k) << "\n";

    return 0;
}