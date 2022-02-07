#include <iostream>
#include <vector>
using namespace std;

void Permutation(string str, vector<string> &list, string ans)
{
    if (str.length() == 0)
    {
        list.push_back(ans);
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        Permutation(str.substr(0,i)+str.substr(i+1), list,ans+str[i]);
    }
}

int Factorial(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

string Permute(string str,int key,string ans)
{
    if(key<0)
    {
        return "NO";
    }
    if(str.length()==0)
    {
        return ans;
    }

    for(int i=0;i<str.length();i++)
    {
        int Fact=Factorial(str.length()-2-i);
        if(key-Fact<0)
        {
            return Permute(str.substr(0,i-1)+str.substr(i),key,ans+str[i-1]);
        }
        else
        key-=Fact;
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    int k;
    cin>>k;
    cout<<Permute(str,k,"");
    // vector<string> List;
    // Permutation(str, List, "");
    // cout<<List[k-1];
    return 0;
}