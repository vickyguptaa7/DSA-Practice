#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string Choose_And_Swap(string str)
{
    int len = str.length();
    int freq[26] ;
    memset(freq,-1,sizeof(freq));
    for (int i = 0; i < len; i++)
    {
        if (freq[str[i] - 'a'] == -1)
            freq[str[i] - 'a'] = i;
    }
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<str[i]-'a';j++)
        {
            if(freq[j]!=-1)
            {
                break;
            }
        }
        if(j!=str[i]-'a')
        break;
        else 
        freq[str[i]-'a']=-1;
    }
    char a=str[i],b=j+'a';
    if(i!=len)
    {
        for(int k=0;k<len;k++)
        {
            if(str[k]==a)
            {
                str[k]=b;
            }
            else if(str[k]==b)
            {
                str[k]=a;
            }
        }
    }
    return str;
}

int main()
{
    string str;
    cin >> str;
    cout << Choose_And_Swap(str) << endl;
    return 0;
}