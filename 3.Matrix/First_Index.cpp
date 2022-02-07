#include<iostream>
using namespace std;

int First_Index(int arr[],int n)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(arr[mid]==1&&arr[mid-1]!=1)
        {
            return mid;
        }
        else if(arr[mid]<1)
        {
            i=mid+1;
        }
        else 
        {
            j=mid-1;
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

    cout<<First_Index(arr,n)<<endl;

    return 0;
}