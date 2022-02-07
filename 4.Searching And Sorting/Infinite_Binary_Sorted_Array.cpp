#include<iostream>
using namespace std;

int Infinite_Binary_Array(long long int arr[],long long int key)
{
    int i=0,j=1;
    while(arr[j]<key)
    {
        i=j;
        j*=2;
    }
    long long ans=-1;
    while(j>=i)
    {
        long long mid=i+(j-i)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            j=mid-1;
        }
        else if(arr[mid]<key)
        {
            i=mid+1;
        }
    }
    return ans;
}

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
    {
        if(i<n/4)
        arr[i]=0;
        else 
        arr[i]=1;
    }
    long long int key;
    key=1;
    cout<<Infinite_Binary_Array(arr,key);
    return 0;
}