#include<iostream>
using namespace std;

int Reverse_Binary_Search(int arr[],int n,int k)
{
    int i=0,j=n-1;
    while(j>=i)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==k)return 1;
        else if(arr[mid]<k)
        {
            j=mid-1;
        }
        else 
        {
            i=mid+1;
        }
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
    cout<<Reverse_Binary_Search(arr,n,k);
    return 0;
}