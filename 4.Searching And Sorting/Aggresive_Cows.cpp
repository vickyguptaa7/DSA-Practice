#include <iostream>
using namespace std;
#include<algorithm>

#define ll long long int

bool isValid(ll arr[],ll n,ll k,ll mid)
{
    ll cows=1,pstall=0;
 
    for(ll i=1;i<n&&cows<k;i++)
    {
        if(arr[i]-arr[pstall]>=mid)
        {
            pstall=i;
            cows++;
        }
    }
    return(cows==k)?1:0;
}

ll B_Search(ll arr[], ll n, ll k)
{
    sort(arr,arr+n);
    ll low=arr[0],high=arr[n-1];
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

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin >> n>> k;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << B_Search(arr, n, k)<<endl;
    }

    return 0;
}