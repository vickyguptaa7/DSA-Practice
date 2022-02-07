#include<iostream>
using namespace std;

void Permute(string str,string ans="")
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        string ros=str.substr(0,i)+str.substr(i+1);
        Permute(ros,ans+ch);
    }
}

int main(){
    string str;
    cin>>str;

    Permute(str);
    return 0;
}