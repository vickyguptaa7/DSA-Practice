#include<iostream>
using namespace std;

int Binary_Search(int *arr,int n,int k)
{
    int low=0,high=n-1,ans=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>k)
        {
            high=mid-1;
        }
        else
        {
            ans=mid;
            low=mid+1;
        }
    }
    return ++ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Binary_Search(arr,n,1)<<endl;
    return 0;
}