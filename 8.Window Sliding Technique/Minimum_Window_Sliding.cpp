#include<iostream>
using namespace std;

bool isValid(int carr[],int sarr[])
{
    for(int i=0;i<256;i++)
    {
        if(!(carr[i]>=sarr[i]))
        {
            return false;
        }
    }
    return true;
}

string Minimum_Substring(string txt,string stxt)
{
    int tlen=txt.length();
    int slen=stxt.length();
    int sarr[256]={0};
    for(int i=0;i<slen;i++)
    {
        sarr[stxt[i]]++;
    }

    int carr[256]={0};
    int i=0,j=0;
    int minlen=INT_MAX;
    string ans="";
    while(j<tlen)
    {
        while(j<tlen&&!isValid(carr,sarr))
        {
            carr[txt[j]]++;
            j++;
        }
        while(isValid(carr,sarr))
        {
            if(minlen>j-i)
            {
                minlen=j-i;
                ans=txt.substr(i,j-i);
            }
            
            carr[txt[i]]--;
            i++;
        }
    }
    return ans;
}

int main(){
    string txt,stxt;
    cin>>txt>>stxt;

    cout<<Minimum_Substring(txt,stxt)<<endl;
    return 0;
}