#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int Maximum_Stock_Buy(vector<int>stock,int n,int k)
{
    vector<pair<int,int>>stck;
    for(int i=0;i<n;i++)
    {
        stck.push_back({stock[i],i+1});
    }
    sort(stck.begin(),stck.end());
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(k>=stck[i].first)
        {
            int d=min((k/stck[i].first),stck[i].second);
            count+=d;
            k-=d*stck[i].first;
        }
        else break;
    }
    return count;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>stock(n);
    for(int i=0;i<n;i++)cin>>stock[i];
    cout<<Maximum_Stock_Buy(stock,n,k)<<endl;
    return 0;
}