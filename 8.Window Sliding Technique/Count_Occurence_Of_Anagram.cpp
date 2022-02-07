#include<iostream>
using namespace std;

int Count_Anagrams(string txt,int n,string pat,int k)
{
    int parr[26]={0},arr[26]={0};
    for(int i=0;i<k;i++)
    {
        parr[pat[i]-'a']++;
    }

    int i=0,j=0;
    int count=0;
    while(j<n)
    {
        arr[txt[j]-'a']++;
        if(j-i+1<k)j++;
        else if(j-i+1==k)
        {
            bool chk=true;
            for(int p=0;p<26;p++)
            {
                if(arr[p]!=parr[p])
                {
                    chk=false;
                    break;
                }
            }
            if(chk)count++;
            arr[txt[i]-'a']--;
            i++;
            j++;
        }
    }
    return count;
}
 
int main(){
    string txt,pat;
    cin>>txt>>pat;
    int n=txt.length();
    int k=pat.length();
    cout<<Count_Anagrams(txt,n,pat,k);
    return 0;
}