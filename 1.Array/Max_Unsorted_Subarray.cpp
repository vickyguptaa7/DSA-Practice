#include<iostream>
using namespace std;

void Longest_Subarray(int arr[],int n)
{
    int s,l;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        {
            s=i;
            break;
        }
    }
    for(int i=n-1;i>s;i--)
    {
        if(arr[i-1]>arr[i])
        {
            l=i;
            break;
        }
    }
    int tmax=INT_MIN,tmin=INT_MAX;
    for(int i=s;i<=l;i++)
    {
        tmax=max(tmax,arr[i]);
        tmin=min(tmin,arr[i]);
    }
    for(int i=0;i<s;i++)
    {
        if(tmin<=arr[i])
        {
            s--;
        }
    }
    for(int i=l+1;i<n;i++)
    {
        if(tmax>=arr[i])
        {
            l++;
        }
    }

    cout<<"Longest Unsorted Array Length : "<<s<<" , "<<l<<endl;
    for(int i=s;i<=l;i++)
    {
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Longest_Subarray(arr,n);

    return 0;
}