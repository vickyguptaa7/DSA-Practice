#include<iostream>
using namespace std;

int Check_Sort(int arr[],int n)
{
    if(n==1&&arr[n]>=arr[n-1])
    {
        return 1;
    }
    else if(arr[n]<arr[n-1])
    {
        return 0;
    }
    return Check_Sort(arr,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<Check_Sort(arr,n-1)<<endl;
    return 0;
}