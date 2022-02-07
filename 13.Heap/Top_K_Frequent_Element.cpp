#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Top_K_Frequent_Brute(vector<int> arr, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size(); i++)
        umap[arr[i]]++;
    vector<pair<int, int>> vp;
    for (auto x : umap)
    {
        vp.push_back({x.second, x.first});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(vp[i].second);
    }
    return ans;
}

vector<int> Top_K_Frequent_Optimal(vector<int> arr, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size(); i++)
        umap[arr[i]]++;
    vector<pair<int, int>> vp;
    for (auto x : umap)
    {
        vp.push_back({x.second, x.first});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < vp.size(); i++)
    {
        pq.push(vp[i]);
        if (k < pq.size())
        {
            pq.pop();
        }
    }

    vector<int> ans;
    while (pq.size())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    Print(Top_K_Frequent_Brute(arr, k));
    Print(Top_K_Frequent_Optimal(arr, k));
    return 0;
}