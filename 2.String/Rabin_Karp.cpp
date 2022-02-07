#include<iostream>
#include<cmath>
using namespace std;
#define prime 101

long long int Hash(string str,int k)
{
    long long int hcode=0;
    for(int i=0;i<k;i++)
    {
        hcode+=str[i]*pow(prime,i);
    }
    return hcode;
}
bool Search(string str,string ptt,int l)
{
    for(int i=0;i<ptt.length();i++)
    {
        if(str[l+i]!=ptt[i])return 0;
    }
    
    return 1;
}
void Find_Pattern(string str,string ptt)
{
    int plen=ptt.length();
    
    long long int hpcode=Hash(ptt,plen);
    long long int hscode=Hash(str,plen);

    if(hscode==hpcode)
    {
        if(Search(str,ptt,0))cout<<0<<" ";
    }
    for(int i=plen;i<str.length();i++)
    {
        hscode-=str[i-plen];
        hscode/=prime;
        hscode+=str[i]*pow(prime,plen-1);
        if(hscode==hpcode)
        {
            if(Search(str,ptt,i-plen+1))
            {
                cout<<i-plen+1<<" ";
            }
        }
    }
    cout<<endl;
}

int main(){
    string str,ptt;
    getline(cin,str);
    getline(cin,ptt);
    
    Find_Pattern(str,ptt);
    return 0;
}