#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int Purchase_Max_Brute(vector<int> arr, int k)
{
    int res = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; k >= arr[i]; i++)
    {
        k -= arr[i];
        res++;
    }
    return res;
}

int Purchase_Max_Optimal(vector<int> arr, int k)
{
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    while (pq.top() <= k)
    {
        k -= pq.top();
        pq.pop();
        res++;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Purchase_Max_Brute(arr, k) << endl
         << Purchase_Max_Optimal(arr, k);
    return 0;
}