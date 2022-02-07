#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Profit(int arr[], int n)
{
    vector<int> left_buy, right_buy;
    int min_till = 1e9, max_till = -1e9;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min_till)
            min_till = arr[i];
        profit = max(profit, arr[i] - min_till);
        left_buy.push_back(profit);
    }
    profit = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max_till)
            max_till = arr[i];
        profit = max(profit, max_till - arr[i]);
        right_buy.push_back(profit);
    }
    reverse(right_buy.begin(), right_buy.end());
    profit = 0;
    for (int i = 0; i < n; i++)
    {
        profit = max(profit, left_buy[i] + right_buy[i]);
    }
    return profit;
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
    cout << Max_Profit(arr, n) << "\n";
    return 0;
}
/*
6
10 22 5 75 65 80

7
2 30 15 10 8 25 80

7
100 30 15 10 8 25 80

5
90 80 70 60 50
*/