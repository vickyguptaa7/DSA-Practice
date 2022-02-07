#include<iostream>
using namespace std;

int Count_Subseq(int arr[],int ind,int n,int sum,int k)
{
    if(ind==n)
    {
        if(sum%k==0)
        {
            return 1;
        }
        else return 0;
    }
    sum+=arr[ind];
    int rcount=Count_Subseq(arr,ind+1,n,sum,k);
    sum-=arr[ind];
    int lcount=Count_Subseq(arr,ind+1,n,sum,k);
    return lcount+rcount;
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
    cout<<Count_Subseq(arr,0,n,0,k)<<endl;
    return 0;
}