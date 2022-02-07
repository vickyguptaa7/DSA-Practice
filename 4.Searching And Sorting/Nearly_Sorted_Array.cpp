#include<iostream>
using namespace std;

int Search(int arr[],int n,int k)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==k)return mid;
        else if(mid>0&&arr[mid-1]==k)return mid-1;
        else if(mid<n-1&&arr[mid+1]==k)return mid+1;
        else if(arr[mid]>k) j=mid-1;
        else i=mid+1;
    }
    return -1;
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
    cout<<Search(arr,n,k)<<endl;

    return 0;
}