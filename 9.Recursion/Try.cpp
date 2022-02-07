#include<iostream>
#include<vector>
using namespace std;

void Balanced_Parenthesis(int op,int cl,string st,vector<string>&ans)
{
    if(op==0&&cl==0)
    {
        ans.push_back(st);
        return;
    }
    if(op>0)
    Balanced_Parenthesis(op-1,cl,st+'(',ans);
    if(cl>op)
    Balanced_Parenthesis(op,cl-1,st+')',ans);
}

int main(){
    int n;
    cin>>n;
    vector<string>ans;
    Balanced_Parenthesis(n,n,"",ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}