#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

struct interval
{
    int strt;
    int end;
};

bool myComp(interval a,interval b)
{
    return (a.strt<b.strt)?1:0;
}

stack<interval> Merge_Intervals(interval arr[],int n)
{
    stack<interval> ans;
    if(n==0)return ans;
    ans.push(arr[0]);
    if(n==1)return ans;
    
    sort(arr,arr+n,myComp);

    for(int i=1;i<n;i++)
    {
        interval top=ans.top();
        
        if(top.end<arr[i].strt)
        {
            ans.push(arr[i]);
        }
        else
        {
            top.end=max(top.end,arr[i].end);
            ans.pop();
            ans.push(top);
        }
    }
    return ans;
}

void Display(stack<interval> ans)
{
    while(!ans.empty())
    {
        cout<<ans.top().strt<<" "<<ans.top().end<<endl;
        ans.pop();
    }
}

int main(){
    int n;
    cin>>n;
    interval arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].strt>>arr[i].end;
    }

    stack<interval> ans=Merge_Intervals(arr,n);
    
    Display(ans);
    return 0;
}