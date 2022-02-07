#include<iostream>
#include<vector>
using namespace std;

bool isPallindrome(string str,int s,int e)
{
    while(s<=e)
    {
        if(str[s++]!=str[e--])
        {
            return false;
        }
    }
    return true;
}

void Partition(string str,vector<string>&ans,vector<vector<string>>&list)
{
    if(str.length()==0)
    {
        list.push_back(ans);
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        if(isPallindrome(str,0,i))
        {
            ans.push_back(str.substr(0,i+1));
            Partition(str.substr(i+1),ans,list);
            ans.pop_back();
        }
    }
}

vector<vector<string>> Pallindrome_Partition(string str)
{
    vector<vector<string>>list;
    vector<string>ans;
    Partition(str,ans,list);
    return list;
}

int main(){
    string str;
    cin>>str;
    vector<vector<string>>list=Pallindrome_Partition(str);
    for(int i=0;i<list.size();i++)
    {
        for(int j=0;j<list[i].size();j++)
        {
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}