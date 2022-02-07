#include<iostream>
#include<algorithm>
using namespace std;

int Meeting_Maximum_Optimal(int arr[],int dep[],int n)
{
    sort(dep,dep+n);
    sort(arr,arr+n);

    int i=0,j=0;
    int Max=0;
    int guest=0;
    while(i<n)
    {
        if(dep[j]>arr[i])
        {
            guest++;
            i++;
        }
        else
        {
            guest--;
            j++;
        }
        Max=max(guest,Max);
    }
    return Max;
}

int Meeting_Maximum(int arr[],int dep[],int n)
{
    int Max=0;
    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=i+1;j<n;j++)
        {
            if((arr[i]>=arr[j]&&arr[i]<=dep[j])
            ||dep[j]>=arr[i]&&dep[j]<=dep[i])
            count++;
        }
        Max=max(Max,count);
    }
    return Max;
}

int main(){
    int n;
    cin>>n;
    int arrival[n];
    int depart[n];

    for(int i=0;i<n;i++)
    {
        cin>>arrival[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>depart[i];
    }

    cout<<Meeting_Maximum(arrival,depart,n)<<endl;
    cout<<Meeting_Maximum_Optimal(arrival,depart,n)<<endl;

    return 0;
}