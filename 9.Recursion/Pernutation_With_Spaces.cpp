#include<iostream>
using namespace std;

void Permute_Spaces(string str,int i=1) // In this We Are Changing Our Variable Str Dont Do Like This
{
    if(str.length()<=i)
    {
        cout<<str<<endl;
        return;
    }
    Permute_Spaces(str,i+1);
    Permute_Spaces(str.insert(i,"_"),i+2);
}

void Permute_With_Spaces(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    Permute_With_Spaces(str.substr(1),ans+str[0]);
    Permute_With_Spaces(str.substr(1),ans+"_"+str[0]);
}

int main(){
    string str;
    cin>>str;
    Permute_With_Spaces(str.substr(1),str.substr(0,1));
    return 0;
}