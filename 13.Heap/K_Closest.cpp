#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> K_Closest_Brute(vector<int> arr, int num, int k)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < arr.size(); i++)
    {
        vp.push_back({abs(num - arr[i]), arr[i]});
    }
    sort(vp.begin(), vp.end());
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(vp[i].second);
    }
    return ans;
}

vector<int> K_Closest_Optimal(vector<int> arr, int num, int k)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < arr.size(); i++)
    {
        vp.push_back({abs(num - arr[i]), arr[i]});
    }
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < vp.size(); i++)
    {
        pq.push(vp[i]);
        if (pq.size() > k)
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
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int num, k;
    cin >> num >> k;

    Print(K_Closest_Brute(arr, num, k));
    Print(K_Closest_Optimal(arr, num, k));
    return 0;
}