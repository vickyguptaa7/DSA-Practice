#include<iostream>
using namespace std;

string Longest_Substring(string str)
{
    if(str.length()<=1)
    {
        return str;
    }

    
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        
        string ans=Longest_Substring(str);

        cout<<ans<<endl;
    }
    return 0;
}