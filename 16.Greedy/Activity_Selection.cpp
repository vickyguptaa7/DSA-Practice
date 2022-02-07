#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second<p2.second;
}

int Max_Activity_Selection(vector<pair<int,int>>Time,int n)
{
    sort(Time.begin(),Time.end(),mycomp);
    for(auto x:Time)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    int Max_Activity=1,last_added=0;
    for(int i=1;i<n;i++)
    {
        if(Time[last_added].second>Time[i].first)continue;
        Max_Activity++;
        last_added=i;
    }
    return Max_Activity;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>Time;
    for(int i=0;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        Time.push_back({t1,t2});
    }
    cout<<Max_Activity_Selection(Time,n)<<endl;
    return 0;
}
/*
6
5 9 
1 2 
3 4 
0 6
5 7
8 9
*/