#include<iostream>
using namespace std;

int Max_K_Sum(int arr[],int n,int k)
{
    if(k<=0||k>n)return -1;
    int i=0,j=k,sum=0;
    for(int m=0;m<j;m++)sum+=arr[m];
    int maxsum=sum;

    while(j<n)
    {
        sum+=arr[j++]-arr[i++];
        maxsum=max(sum,maxsum);
    }
    return maxsum;
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
    
    cout<<Max_K_Sum(arr,n,k)<<endl;

    return 0;
}