#include<iostream>
using namespace std;

int* Product_Division(int arr[],int n) //T.C-> O(n) and S.C -> O(1)
{
    int *ans=new int[n];
    int count=0;
    long long int pro=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        pro*=arr[i];
        else
        count++;
    }

    for(int i=0;i<n;i++)
    {
        if(count==0) ans[i]=pro/arr[i];
        
        else if(count==1)
        {
            if(arr[i]==0) ans[i]=pro;
            else ans[i]=0;
        }
        else 
        {
            ans[i]=0;
        }
    }
    return ans;
}

int* Product_No_Division(int arr[],int n) //T.C-> O(n) and S.C -> O(n)
{
    int *ans=new int[n];
    int lp[n],rp[n];
    int pro=1;
    for(int i=0;i<n;i++)
    {
        pro*=arr[i];
        lp[i]=pro;
    }
    pro=1;
    for(int i=0;i<n;i++)
    {
        pro*=arr[n-i-1];
        rp[n-1-i]=pro;
    }

    for(int i=0;i<n;i++)
    {
        if(i>0&&i<n-1)
        {
            ans[i]=lp[i-1]*rp[i+1];
        }
        else if(i==0)
        {
            ans[i]=rp[i+1];
        }
        else
        {
            ans[i]=lp[i-1];
        }
    }
    return ans;
}

int* Product_Optimal(int arr[],int n) //T.C-> O(n) and S.C -> O(1)
{
    int *ans=new int[n];
    long long int pro=1;
    for(int i=0;i<n;i++)
    {
        pro*=arr[i];
        ans[i]=pro;
    }
    pro=1;
    for(int i=n-1;i>0;i--)
    {
            ans[i]=ans[i-1]*pro;
            pro*=arr[i];
    }
    ans[0]=pro;
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

    int *ans=Product_Optimal(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}