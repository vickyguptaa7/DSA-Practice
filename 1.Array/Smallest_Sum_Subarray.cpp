#include<iostream>
using namespace std;

int Smallest_Sum(int *arr,int n,int k)
{
    int count=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(k<sum)
            {
                count=min(count,j-i+1);
            }
        }
    }
    return count;
}

int Smallest_Sum_Subarray(int *arr, int n,int k)
{
    int i=0,j=0;
    int sum=0,count=n+1;
    while(j<n)
    {
        while(sum<=k&&j<n)
        {
            sum+=arr[j];
            j++;
        }
        while(sum>k&&i<n)
        {
            count=min(count,j-i);
            sum-=arr[i];
            i++;
        }
    }
    return count;
}

int main(){
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Smallest_Sum_Subarray(arr,n,k)<<endl;

    return 0;
}