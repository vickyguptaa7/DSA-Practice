#include<iostream>
using namespace std;

int Split_Binary(string str)
{
    int len=str.length();
    if(len%2==1||len==0)return -1;

    int i=0,j=0,count=0,in=0;
    for(int k=0;k<len;k++)
    {
        if(str[k]=='0')i++;
        if(str[k]=='1')j++;
        if(i==j)
        {
            count++;
            for(int l=in;l<=k;l++)
            {
                cout<<str[l];
            }
            cout<<endl;
            in=k+1;
        }
    }
    return count;
}

int main(){
    string bstr;
    cin>>bstr;

    cout<<Split_Binary(bstr)<<endl;

    return 0;
}