#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Freq_Sort_1(vector<int> arr)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size(); i++)
        umap[arr[i]]++;
    vector<pair<int, int>> vp;
    for (auto x : umap)
        vp.push_back({x.second, x.first});
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    vector<int> ans;
    for (int i = 0; i < vp.size(); i++)
    {
        int loop=vp[i].first;
        while(loop--)
        ans.push_back(vp[i].second);
    }
        
    return ans;
}

vector<int> Freq_Sort_2(vector<int> arr)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size(); i++)
        umap[arr[i]]++;
    priority_queue<pair<int, int>> pq;
    for (auto x : umap)
        pq.push({x.second, x.first});
    vector<int> ans;
    while (pq.size())
    {
        int loop=pq.top().first;
        while(loop--)
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

    Print(Freq_Sort_1(arr));
    Print(Freq_Sort_2(arr));
    return 0;
}