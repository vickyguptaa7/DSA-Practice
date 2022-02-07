#include<iostream>
using namespace std;

string X_To_End(string str,int i=0)
{
    if(str.length()==i+1)
    {
        return str;
    }
    if(str[i]=='x')
    {
        str.erase(i,1);
        str+="x";
    }
    return X_To_End(str,i+1);
}

int main(){
    string str;
    cin>>str;
    
    cout<<X_To_End(str)<<endl;
    return 0;
}