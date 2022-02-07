#include<iostream>
using namespace std;

string Pallindrome(string str,int s=0)
{
    if(s==str.length()/2)
    {
        return "Yes";
    }
    if(str[s]!=str[str.length()-1-s])
    {
        return "No";
    }
    return Pallindrome(str,s+1);
}

int main(){
    string str;
    getline(cin,str);
    cout<<Pallindrome(str)<<endl;
    return 0;
}