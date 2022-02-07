#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int min_sprinklers(int gallery[], int n)
{
    vector<int>garden(n,-1);
    vector<pair<int,int>>water;
    for(int i=0;i<n;i++)
    {
        if(gallery[i]!=-1&&gallery[i]!=0)
        {
            water.push_back({gallery[i],i});
        }
        if(gallery[i]==0)garden[i]=i;
    }
    sort(water.begin(),water.end());
    for(int i=0;i<water.size();i++)
    {
        int st=(water[i].second-water[i].first<0)?0:water[i].second-water[i].first;
        int end=(water[i].second+water[i].first>n)?n-1:water[i].second+water[i].first;
        for(int j=st;j<=end;j++)
        {
            garden[j]=water[i].second;
        }
    }
    unordered_set<int>uset;
    for(int i=0;i<n;i++)
    {
        cout<<garden[i]<<" ";
        if(garden[i]==-1)return -1;
        uset.insert(garden[i]);
    }
    cout<<endl;
    return uset.size();
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<min_sprinklers(arr,n)<<endl;
    return 0;
}