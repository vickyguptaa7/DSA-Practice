#include<iostream>
using namespace std;

bool isValid(int arr[],int n,int k,int mid)
{
    int st=1,sum=0;
     
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
        {
            st++;
            sum=arr[i];
        }
        if(st>k)
        {
            return 0;
        }
    }
    return 1;
}

int B_Search(int arr[],int n,int k)
{
    if(n<k) return -1;
    int i=0,j=0;
    for(int k=0;k<n;k++)
    {
        i=max(i,arr[k]);
        j+=arr[k];
    }
    if(n==k) return i;
    int ans=-1;
    while(j>=i)
    {
        int mid=i+(j-i)/2;
        if(isValid(arr,n,k,mid))
        {
            ans=mid;
            j=mid-1;
        }
        else 
        {
            i=mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<B_Search(arr,n,k);
    return 0;
}