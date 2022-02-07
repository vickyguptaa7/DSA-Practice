#include<iostream>
using namespace std;

int Sqrt_Better(int n) // T.C -> O(sqrtn)
{
    int i=1;
    while(i*i<n)i++;
    return --i;
}

int Sqrt_Optimal(int n) // T.C -> O(logn)
{
    int i=0,ans=0;
    while(i<=n)
    {
        int mid=(i+n)/2;
        if(mid*mid==n)
        {
            ans=mid;
        }
        else if(mid*mid>n)
        {
            n=mid-1;
        }
        else{
            i=mid+1;
            ans=mid;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<Sqrt_Optimal(n);
    return 0;
}