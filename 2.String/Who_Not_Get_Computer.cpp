#include<iostream>
using namespace std;

int Get_Not_Computer(string str,int n,int ncp)
{
    int carr[26]={0},noget=0;
    for(int i=0;i<n;i++)
    {
        if(carr[str[i]-'A']==0)
        {
            int count=0;
            for(int j=0;j<26;j++)
            {
                if(carr[j]==1)count++;
            }
            if(count>=ncp)noget++;
            carr[str[i]-'A']=1;
        }
        else carr[str[i]-'A']--;
    }
    return noget;
}

int main(){
    string str;
    cin>>str;
    int len=str.length();
    int ncp;
    cin>>ncp;
    cout<<Get_Not_Computer(str,len,ncp)<<endl;
    return 0;
}