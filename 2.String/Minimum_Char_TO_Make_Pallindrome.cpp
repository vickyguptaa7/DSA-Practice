#include<iostream>
#include<algorithm>
using namespace std;

string Minimum_Char_Brute(string str)
{
    string res="";
    while(true)
    {
        int n=str.length();
        bool chk=true;
        for(int i=0;i<(n)/2;i++)
        {
            if(str[i]!=str[n-i-1])
            {
                chk=false;
                break;
            }
        }
        if(chk)
        {
            break;
        }

        else
        {
            res+=str[n-1];
            str.erase(n-1,1);
        }
    }
    return (res!="")?res:"-1";
}

int* LPS_Array(string str)
{
    int *lps=new int[str.length()];
    int i=0,j=1;
    lps[0]=0;
    while(j<str.length())
    {
        if(str[i]==str[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=lps[i-1];
            }
            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
    return lps;
}

int Minimum_Char_Optimal(string str)
{
    string strev=str;
    reverse(strev.begin(),strev.end());
    string combine=str+"-"+strev;
    int *lps=LPS_Array(combine);

    return str.length()-lps[combine.length()-1];
}

int main(){
    string str;
    getline(cin,str);
    // string ans=Minimum_Char_Brute(str);//return the string which must add to make pallindrome
    // cout<<ans<<endl;
    // cout<<Minimum_Char_Optimal(str)<<endl; //return integer the size of the substring
    int *arr=LPS_Array(str);
    for(int i=0;i<str.length();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}