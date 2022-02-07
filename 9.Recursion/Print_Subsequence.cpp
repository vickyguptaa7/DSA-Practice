#include<iostream>
using namespace std;

void Subsequence(string str,string ans="")
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    Subsequence(str.substr(1),ans);

    Subsequence(str.substr(1),ans+str[0]);
}

int main(){
    string str;
    cin>>str;

    Subsequence(str);
    return 0;
}