#include<iostream>
using namespace std;

int Moore_Algo(int arr[],int n)
{
    int freq=1,prev=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]==prev)
        {
            freq++;
        }
        else 
        {
            freq--;
        }
        if(freq==0)
        {
            prev=arr[i];
            freq++;
        }
    }
    
    freq=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==prev)
        {
            freq++;
        }
    }
    if(freq>n/2)
    {
        return prev;
    }
    else return -1;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Moore_Algo(arr,n)<<endl;

    return 0;
}