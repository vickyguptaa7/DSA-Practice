#include<iostream>
using namespace std;

int Min_Diff(int arr[],int n,int key)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]==key) return arr[mid];
        else if(arr[mid]>key)
        {
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
    }
   return(abs(key-arr[i])>abs(key-arr[j]))?arr[j]:arr[i];
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
    cout<<Min_Diff(arr,n,key)<<endl;
    return 0;
}