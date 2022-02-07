#include<iostream>
using namespace std;

int unique_element(int carr[])
{
    int count=0;
    for(int l=0;l<26;l++)
    {
        if(carr[l]!=0)count++;
    }
    return count;
}

int Longest_Substring(string str,int len,int k)
{
    int carr[26]={0};
    int i=0,j=0;
    int maxlen=0;
    while(j<len)
    {
        carr[str[j]-'a']++;
        if(unique_element(carr)==k)
        {
            maxlen=max(maxlen,j-i+1);   
        }
        else if(unique_element(carr)>k) 
        {
            while(unique_element(carr)>k)
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
    int k;
    cin>>k;
    cout<<Longest_Substring(str,len,k)<<endl;
    return 0;
}