#include<iostream>
using namespace std;

int Max_Sum(int arr[],int n,int k)
{
    int Max=0;
    for(int i=0;i<k;i++)
    {
        Max+=arr[i];
    }

    int i=1,j=k;
    while(j<n)
    {
        Max=max(arr[j]-arr[i-1]+Max,Max);
        i++;
        j++;
    }
    return Max;
}

int main(){
    int n,k;
    cin >> n>>k;
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout<<Max_Sum(arr,n,k)<<endl;
    return 0;
}