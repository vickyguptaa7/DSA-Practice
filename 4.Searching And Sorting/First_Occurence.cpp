#include<iostream>
using namespace std;

int Last_Occurence(int arr[],int n,int key)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(arr[mid]>key)
        {
            i=mid+1;
        }
        else if(arr[mid]<key)
        {
            i=mid+1;
        }
        else
        {
            if(mid==n-1||arr[mid+1]!=key)
            {
                return mid;
            }
            else
            {
                i=mid+1;
            }
        }
    }
    return -1;
}


int First_Occurence(int arr[],int n,int key)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(arr[mid]>key)
        {
            i=mid+1;
        }
        else if(arr[mid]<key)
        {
            i=mid+1;
        }
        else
        {
            if(mid==0||arr[mid-1]!=key)
            {
                return mid;
            }
            else
            {
                j=mid-1;
            }
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
    int key;
    cin>>key;
    cout<<Last_Occurence(arr,n,key);
    return 0;
}