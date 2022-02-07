#include<iostream>
#include<queue>
using namespace std;

void First_Negative_Brute(int arr[],int n,int k)
{
    for(int i=0;i<=n-k;i++)
    {
        bool pos=true;
        for(int j=i;j<i+k;j++)
        {
            if(arr[j]<0)
            {
                pos=false;
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(pos)cout<<"0"<<" ";
    }
}

void First_Negative_Optimal(int arr[],int n,int k)
{
    queue<int>q;
    int i=0,j=0;
    while(j<n)
    {
        while(j-i!=k)
        {
            if(arr[j]<0)
            {
                q.push(arr[j]);
            }
            j++;
        }
        if(q.empty())
        {
            cout<<"0"<<" ";
        }
        else
        {
            cout<<q.front()<<" ";
        }
        if(arr[i]==q.front())
        {
            q.pop();
        }
        i++;
    }
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
    
    First_Negative_Optimal(arr,n,k);
    return 0;
}