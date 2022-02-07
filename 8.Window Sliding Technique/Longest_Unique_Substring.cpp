#include<iostream>
using namespace std;

int All_Unique(int carr[])
{
    for(int i=0;i<26;i++)
    {
        if(carr[i]>1)return 0;
    }
    return 1;
}

int Longest_Unique_Substring(string str,int n)
{
    int carr[26]={0};
    int i=0,j=0;
    int maxlen=-1;
    while(j<n)
    {
        carr[str[j]-'a']++;
        if(All_Unique(carr))
        {
            maxlen=max(maxlen,j-i+1);
        }
        else
        {
            while(!All_Unique(carr))
            {
                carr[str[i]-'a']--;
                i++;
            }
        }
        j++;
    }
    return maxlen;
}

int main(){
    string str;
    cin>>str;
    int len=str.length();
    cout<<Longest_Unique_Substring(str,len)<<endl;
    return 0;
}