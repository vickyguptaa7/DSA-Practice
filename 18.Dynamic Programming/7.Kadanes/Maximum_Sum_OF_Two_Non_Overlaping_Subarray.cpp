#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Largest_Sum_Till_Index_left(int arr[], int n, int k)
{
    vector<int> ans;
    int K_Sum = 0;
    for (int i = 0; i < k; i++)
    {
        K_Sum += arr[i];
        ans.push_back(K_Sum);
    }
    int Max_Sum = K_Sum;
    for (int i = k; i < n; i++)
    {
        K_Sum += arr[i] - arr[i - k];
        if (Max_Sum < K_Sum)
            Max_Sum = K_Sum;
        ans.push_back(Max_Sum);
    }
    return ans;
}

vector<int> Largest_Sum_Till_Index_right(int arr[], int n, int k)
{
    vector<int> ans;
    int K_Sum = 0;
    for (int i = n - 1; i >= n - k; i--)
    {
        K_Sum += arr[i];
        ans.push_back(K_Sum);
    }
    int Max_Sum = K_Sum;
    for (int i = n - k - 1; i >= 0; i--)
    {
        K_Sum += arr[i] - arr[i + k];
        if (Max_Sum < K_Sum)
            Max_Sum = K_Sum;
        ans.push_back(Max_Sum);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int Max_Sum_Two_Non_Overlaping_Subarray(int arr[], int n, int k1, int k2)
{
    if (k1 + k2 > n)
    {
        cout << " Not_Possible "
             << "\n ";
        return -1;
    }
    vector<int> dp1 = Largest_Sum_Till_Index_left(arr, n, k1);
    vector<int> dp2 = Largest_Sum_Till_Index_right(arr, n, k2);
    int result = 0;

    for (int i = k1 - 1; i <= n - k2; i++)
    {
        result = max(result, dp1[i] + dp2[i + 1]);
    }

    dp1 = Largest_Sum_Till_Index_right(arr, n, k1);
    dp2 = Largest_Sum_Till_Index_left(arr, n, k2);

    for (int i = k2 - 1; i <= n - k1; i++)
    {
        result = max(result, dp1[i + 1] + dp2[i]);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k1, k2;
    cin >> k1 >> k2;
    cout << Max_Sum_Two_Non_Overlaping_Subarray(arr, n, k1, k2) << "\n";
    return 0;
}
/*
9
0 6 5 2 2 5 1 9 4
1 2

9
3 8 1 3 2 1 8 9 0
2 3

10
2 1 5 6 0 9 5 0 3 8
4 4

*/