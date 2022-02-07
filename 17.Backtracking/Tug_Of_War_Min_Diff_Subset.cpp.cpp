#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Min_Diff_Two_Set(vector<int> arr, int i, int sum1, int sum2, int &min_diff, vector<int> set1, vector<int> set2, vector<vector<int>> &res)
{
    if (i == arr.size())
    {
        if (min_diff > abs(sum1 - sum2))
        {
            while (!res.empty())
            {
                res.pop_back();
            }
            res.push_back(set1);
            res.push_back(set2);
            min_diff=abs(sum1-sum2);
        }
        return;
    }
    if (set1.size() < (arr.size() + 1) / 2)
    {
        set1.push_back(arr[i]);
        Min_Diff_Two_Set(arr, i + 1, sum1 + arr[i], sum2, min_diff, set1, set2, res);
        set1.pop_back();
    }
    if (set2.size() < (arr.size() + 1) / 2)
    {
        set2.push_back(arr[i]);
        Min_Diff_Two_Set(arr, i + 1, sum1, sum2 + arr[i], min_diff, set1, set2, res);
        set2.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> set1, set2;
    vector<vector<int>> res;
    int min_diff = 1e9;
    Min_Diff_Two_Set(arr, 0, 0, 0, min_diff, set1, set2, res);
    for (int i = 0; i < 2; i++)
    {
        for (auto x : res[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

/*
23 45 -34 12 0 98 -99 4 189 -1 4
*/