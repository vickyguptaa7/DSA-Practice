#include<iostream>
using namespace std;

int Get_Sum(int arr[],int n,int i,int j)
{
    int presum[n];
    int sum=0;
    for(int k=0;k<n;k++)
    {
        sum+=arr[k];
        presum[k]=sum;
    }

    return (i>0)?presum[j]-presum[i-1]:presum[j];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Get_Sum(arr,n,3,4);
    return 0;
}