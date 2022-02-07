#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string n1,n2;
    cin>>n1>>n2;
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    int len=max(n1.length(),n2.length()),i=0;

    string ans;
    int carry=0;
    while(i<len)
    {
        int num=carry;
        if(n1.length()>i)
        {
            num+=n1[i]-48;
        }
        if(n2.length()>i)
        {
            num+=n2[i]-48;
        }
        carry=0;
        if(num>9)
        {
            carry=num/10;
            num%=10;
        }
        ans+=to_string(num);
        i++;
    }
    if(carry==1)
    ans+="1";

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}