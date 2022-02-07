#include<iostream>
using namespace std;

#define ll long long int 

bool isValid(ll arr[],int n,ll k,ll mid)
{
    ll cut=0;
    for(int i=0;i<n&&cut<k;i++)
    {
        if(mid<arr[i])cut+=arr[i]-mid;
    }
    return (cut>=k)?1:0;
}

int Required_Cut(ll arr[],int n,ll k)
{
    ll low=0,high=0;
    for(int i=0;i<n;i++)high=max(high,arr[i]);
    
    ll ans=-1;
    while(high>=low)
    {
        ll mid=low+(high-low)/2;
        if(isValid(arr,n,k,mid))
        {
            ans=mid;
            low=mid+1;
        }
        else 
        {
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    ll k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Required_Cut(arr,n,k)<<endl;
    return 0;
}