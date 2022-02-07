#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int Airthematic_Slice_Subseq(int arr[], int n)
{
    vector<unordered_map<int, int>> dp(n);
    int Slice_Count = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = arr[i] - arr[j];
            dp[i][diff]++;
            if (dp[j].find(diff) != dp[j].end())
            {
                Slice_Count += dp[j][diff];
                dp[i][diff] += dp[j][diff];
            }
        }
    }
    return Slice_Count;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Airthematic_Slice_Subseq(arr, n) << "\n";
    return 0;
}