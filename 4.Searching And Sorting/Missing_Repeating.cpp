#include<iostream>
#include<algorithm>
using namespace std;

int* Missing_Repeating(int *arr,int n)
{
    int sum=0,sqsum=0;
    for(int i=0;i<n;i++)
    {
        sqsum+=arr[i]*arr[i];
        sum+=arr[i];
    }
    sum=(n*(n+1))/2-sum;
    sqsum=(n*(n+1)*(2*n+1))/6-sqsum;
    sqsum=sqsum/sum;

    int *ans=new int[2];
    ans[0]=(sqsum-sum)/2;
    ans[1]=(sqsum+sum)/2;
    return ans;
}

int* Missing_Repeating_Optimal(int arr[],int n)
{
    int *ans=new int[2];
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1]>0)
        {
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
        else
        {
            ans[0]=abs(arr[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            ans[1]=i+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int *ans=Missing_Repeating_Optimal(arr,n); 

    for(int i=0;i<2;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}