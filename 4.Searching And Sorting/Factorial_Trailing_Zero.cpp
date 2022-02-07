#include<iostream>
using namespace std;

bool isValid(int n,int k)
{
    int sum=0;
    while(n)
    {
        n/=5;
        sum+=n;
    }
    return(sum>=k)?1:0;
}

int Trailing_Zero(int n)
{
    int low=n,high=5*n;
    int ans=-1;
    while(high>=low)
    {
        int mid=low+(high-low)/2;
        if(isValid(mid,n))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<Trailing_Zero(n)<<endl;
    return 0;
}