#include<iostream>
#include<algorithm>
using namespace std;

int Distribute(int arr[],int n,int m)
{
    long long int z=(2<<(n-1));
    int Min=INT_MAX;
    for(long long int i=0;i<z;i++)
    {
        long long int temp=i; int tmax=INT_MIN,tmin=INT_MAX;
        long long int count=0;
        for(int j=0;j<n;j++)
        {
            int rem=temp%2;
            temp/=2;
            if(rem){
                count++;
                tmax=max(tmax,arr[j]);
                tmin=min(tmin,arr[j]);
                }
        }
        if(count==m)
        {
            Min=min(Min,tmax-tmin);
        }
    }
    return Min;
}

int Choclate_Distribute(int arr[],int n,int m)
{
    sort(arr,arr+n);
    int i=0,j=m-1;
    int Min=INT_MAX;
    while(j<n)
    {
        Min=min(Min,arr[j]-arr[i]);
        i++;
        j++;
    }
    return Min;
}

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Choclate_Distribute(arr,n,m);

    return 0;
}