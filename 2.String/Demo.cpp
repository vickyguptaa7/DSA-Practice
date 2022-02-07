#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

struct newArray
{
    string str;
    int ind;
};

bool cmp(newArray a,newArray b)
{
    if(a.str.compare(0,b.str.size(),b.str)==0||
    b.str.compare(0,a.str.size(),a.str)==0)
    {
        return a.str.size()>b.str.size();
    }
    else
    return a.str.size()<b.str.size();
}

int main(){
    int n;
    cin>>n;
    vector<pair<string,int>> string_list(n);
    for(int i=0;i<n;i++)
    {
        string str;
        int num;
        cin>>str;
        cin>>num;
        string_list[i].first=str;
        string_list[i].second=num;
    }
    sort(string_list.begin(),string_list.end());
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<string_list[i].first<<" "<<string_list[i].second<<endl;
    }
    return 0;
}