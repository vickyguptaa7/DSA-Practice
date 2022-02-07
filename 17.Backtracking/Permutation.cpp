#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

void Permute(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        str.erase(i,1);
        Permute(str,ans+ch);
        str.insert(str.begin()+i,ch);
    }
}

void Permute_unique(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        if(i>0&&str[i-1]==str[i])continue;
        char ch=str[i];
        str.erase(i,1);
        Permute_unique(str,ans+ch);
        str.insert(str.begin()+i,ch);
    }
}

int main(){
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    Permute_unique(str,"");
    return 0;
}