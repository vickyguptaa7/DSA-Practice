#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Connect_Ropes_To_Min_Cost(vector<int> arr)
{
    int t_cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    while (pq.size() > 1)
    {
        int r1 = pq.top();
        pq.pop();

        int r2 = pq.top();
        pq.pop();

        pq.push(r1+r2);
        t_cost+=r1+r2;
    }
    return t_cost;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Connect_Ropes_To_Min_Cost(arr) << endl;
    return 0;
}