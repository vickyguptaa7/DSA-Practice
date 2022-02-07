#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(pair<int,int>p1,pair<int,int>p2)
{
    float cost1=(float)p1.second/p1.first;
    float cost2=(float)p2.second/p2.first;
    return cost1>cost2;
}

float Fractional_Knapsack(vector<pair<int,int>>Items,int n,int wt)
{
    sort(Items.begin(),Items.end(),mycomp);
    float price=0;
    for(int i=0;i<n;i++)
    {
        if(wt>=Items[i].first)
        {
            price+=Items[i].second;
            wt-=Items[i].first;
        }
        else
        {
            price+=wt*(Items[i].second/(float)Items[i].first);
            wt-=wt;
            break;
        }
    }
    return price;
}

int main(){
    int n,wt;
    cin>>n>>wt;
    vector<pair<int,int>>Items;
    for(int i=0;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        Items.push_back({t1,t2});
    }
    cout<<Fractional_Knapsack(Items,n,wt)<<endl;
    return 0;
}