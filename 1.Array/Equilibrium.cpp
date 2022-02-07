#include<iostream>
using namespace std;

string Equilibrium_Naive(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int lsum=0,rsum=0;
        for(int j=0;j<i;j++)
        {
            lsum+=arr[j];
        }
        for(int j=i+1;j<n;j++)
        {
            rsum+=arr[j];
        }

        if(lsum==rsum)
        {
            return "Yes";
        }
    }
    return "No";
}

string Equilibrium_Better(int arr[],int n)
{
    int lsum[n];
    int rsum[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        lsum[i]=sum;
    }
    sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=arr[i];
        rsum[i]=sum;
    }


    for(int i=0;i<n;i++)
    {
        if(rsum[i]==lsum[i])
        {
            return "Yes";
        }
    }
    return "No";
}

string Equilibrium_Optimal(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    int lsum=0;
    for(int i=0;i<n;i++)
    {
        if(lsum==sum-arr[i])
        {
            return "Yes";
        }
        lsum+=arr[i];
        sum-=arr[i];
    }
    return "No";
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Equilibrium_Optimal(arr,n)<<endl;

    return 0;
}