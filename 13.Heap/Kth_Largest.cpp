#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void Kth_Largest_Brute(vector<int>arr,int k)
{
    if(arr.size()==0||arr.size()<=k)return;
    sort(arr.begin(),arr.end());
    for(int i=arr.size()-k;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void Kth_Largest_Better(vector<int>arr,int k)
{
    if(arr.size()==0||arr.size()<=k)return;
    priority_queue<int>pq(arr.begin(),arr.end());
    while(k--)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

void Kth_Largest_Optimal(vector<int>arr,int k)
{
    if(arr.size()==0||arr.size()<=k)return;
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(int i=0;i<k;i++)pq.push(arr[i]);

    for(int i=k;i<arr.size();i++)
    {
        if(pq.top()<arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while(k--)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Kth_Largest_Brute(arr,k);
    cout<<endl;
    Kth_Largest_Better(arr,k);
    cout<<endl;
    Kth_Largest_Optimal(arr,k);
    return 0;
}