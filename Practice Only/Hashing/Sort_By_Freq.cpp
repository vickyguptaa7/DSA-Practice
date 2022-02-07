#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    unordered_map<int,int>umap;
    for(int i=0;i<n;i++)umap[arr[i]]++;
    vector<pair<int,int>>store;
    for(auto x:umap)
    {
        pair<int,int>num;
        num.first=x.first;
        num.second=x.second;
        store.push_back(num);
    }
    sort(store.begin(),store.end(),mycomp);
    for(int i=0;i<store.size();i++)
    {
        cout<<store[i].first<<" "<<store[i].second<<endl;
    }
    return 0;
}