#include<iostream>
#include<algorithm>

using namespace std;

int isValid(int arr[],int n,int k,int mid)
{
    int paratha=0;
    for(int i=0;i<n&&paratha<k;i++)
    {
        int time=0,j=1;
        for(j;j<=k;j++)
        {
            time+=j*arr[i];
            if(time>mid) break;
        }
        paratha+=--j;
    }
    return (paratha>=k)?1:0;
}

int Order_Time(int arr[],int n,int k)
{
    int low=0,high=0;
    for(int i=1;i<=k;i++)high+=i*arr[n-1];
    int ans=-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(isValid(arr,n,k,mid))
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
    int t;
    cin>>t;
    while(t--)
    {
        int np,c;
        cin>>np>>c;
        int arr[c];
        for(int i=0;i<c;i++)
        {
            cin>>arr[i];
        }
        cout<<Order_Time(arr,c,np)<<endl;
    }

    return 0;
}