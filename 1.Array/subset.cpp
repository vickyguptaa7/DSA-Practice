#include<iostream>
using namespace std;

void Subset(string str,int n)
{
    int z=(2<<(n-1));
    
    for(int i=0;i<z;i++)
    {
        int num=i;
        for(int j=0;j<n;j++)
        {
            int rem=num%2;
            num/=2;
            if(rem)cout<<str[j];
        }
        cout<<endl;
    }
}

int main(){
    string str;
    cin>>str;

    Subset(str,str.length());

    return 0;
}