#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Kth_Large_Sum_Brute(int arr[],int n,int k)
{
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    return ans[k-1];
}

int Kth_Large_Sum_Optimal(int arr[],int n,int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        arr[i]=sum;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            pq.push(arr[i]);
            else 
            pq.push(arr[j]-arr[i]);
            if(pq.size()>k)
            pq.pop();
        }
    }
    return pq.top();
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<Kth_Large_Sum_Brute(arr,n,k)<<endl;
    cout<<Kth_Large_Sum_Optimal(arr,n,k)<<endl;
    return 0;
}