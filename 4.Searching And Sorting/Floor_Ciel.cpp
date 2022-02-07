#include<iostream>
using namespace std;

int Ciel(int arr[],int n,float k)
{
    int i=0,j=n-1;
    int ans=-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==k) 
        {
            ans=arr[mid];
            j=mid-1;
        }
        else if(arr[mid]>k)
        {
            j=mid-1;
            ans=arr[mid];
        }
        else
        {
            i=mid+1;
        }
    }
    return ans;
}

int Floor(int arr[],int n,float k)
{
    int i=0,j=n-1;
    int ans=-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==k) 
        {
            ans=arr[mid];
            i=mid+1;
        }
        else if(arr[mid]>k)
        {
            j=mid-1;
        }
        else
        {
            i=mid+1;
            ans=arr[mid];
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

    float k;
    cin>>k;
    cout<<Floor(arr,n,k)<<endl;
    cout<<Ciel(arr,n,k)<<endl;
    
    return 0;
}