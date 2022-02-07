#include<iostream>
using namespace std;

void Binary_Prefix(int n,int one,int zero,string ans)
{
    if(n==0)
    {
        cout<<ans<<endl;
        return;
    }
    Binary_Prefix(n-1,one+1,zero,ans+"1");
    if(one>zero)
    Binary_Prefix(n-1,one,zero+1,ans+"0");
    
}

int main(){
    int n;
    cin>>n;

    Binary_Prefix(n,0,0,"");
    return 0;
}