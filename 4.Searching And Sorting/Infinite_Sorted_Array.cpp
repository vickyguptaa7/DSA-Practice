#include<iostream>
using namespace std;

int Infinite_Binary_Search(long long int arr[],long long int key)
{
    int i=0,j=1;
    while(arr[j]<key)
    {
        i=j;
        j*=2;
    }
    
    while(j>=i)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) j=mid-1;
        else i=mid+1;
    }
    return -1;
}

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    long long int key;
    cin>>key;
    cout<<Infinite_Binary_Search(arr,key);
    return 0;
}