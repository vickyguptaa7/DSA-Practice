#include<iostream>
using namespace std;

void Place_Element(int arr[],int n,int val)
{
    if(n==0||arr[n-1]<=val)
    {
        arr[n]=val;
        return;
    }
    int data=arr[n-1];
    Place_Element(arr,n-1,val);
    arr[n]=data;
}

void Sort_Array(int arr[],int n)
{
    if(n==1)
    {
        return;
    }
    Sort_Array(arr,n-1);
    Place_Element(arr,n-1,arr[n-1]);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    cin>>arr[i];

    Sort_Array(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}