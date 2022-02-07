#include<iostream>
#include<vector>

using namespace std;

void Balanced_Parenthesis(int open,int close,string ans,vector<string>&answer)
{
    if(open==0&&close==0)
    {
        answer.push_back(ans);
        return;
    }
    if(open>0)
    Balanced_Parenthesis(open-1,close,ans+"(",answer);
    if(close>open)
    Balanced_Parenthesis(open,close-1,ans+")",answer);
}

int main(){
    int n;
    cin>>n;
    vector<string>answer;
    Balanced_Parenthesis(n,n,"",answer);
    
    int p=answer.size();
    for(int i=0;i<p;i++)
    {
        cout<<answer[i]<<endl;
    }
    return 0;

}