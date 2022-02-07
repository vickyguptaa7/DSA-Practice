#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> K_Closest_Brute(vector<pair<int, int>> vp, int k)
{
    vector<pair<int, int>> ans;
    if (k >= vp.size())
        return ans;
    sort(vp.begin(), vp.end(), [&](pair<int, int> a, pair<int, int> b)
         {
             float d1 = pow(a.first, 2) + pow(a.second, 2);
             float d2 = pow(b.first, 2) + pow(b.second, 2);
             return (d1 < d2);
         });
    for (int i = 0; i < k; i++)
        ans.push_back({vp[i].first, vp[i].second});
    return ans;
}

vector<pair<int,int>>K_Closest_Optimal(vector<pair<int,int>>vp,int k)
{
    vector<pair<int,int>>ans;
    if(k>=vp.size())return ans;
    priority_queue<pair<float,pair<int,int>>>pq;
    for(int i=0;i<vp.size();i++)
    {
        pq.push({pow(vp[i].first, 2) + pow(vp[i].second, 2),{vp[i].first,vp[i].second}});
        if(pq.size()>k)
        pq.pop();
    }
    while(pq.size())
    {
        ans.push_back({pq.top().second.first,pq.top().second.second});
        pq.pop();
    }
    return ans;
}

void Print(vector<pair<int, int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first;
        cin >> vp[i].second;
    }
    Print(K_Closest_Brute(vp, k));
    Print(K_Closest_Optimal(vp,k));
    return 0;
}