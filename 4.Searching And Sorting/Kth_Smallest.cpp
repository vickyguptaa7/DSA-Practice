#include<iostream>
using namespace std;

void Swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int Partition(int arr[],int low,int high)
{
    low--;
    for(int i=low+1;i<high;i++)
    {
        if(arr[i]<arr[high])
        {
            low++;Swap(arr,i,low);
        }
    }
    Swap(arr,high,low+1);
    return (low+1);
}

int Quick_Select(int arr[],int n,int k)
{
    int low=0,high=n-1;

    while(low<=high)
    {
        int p=Partition(arr,low,high);
        if(p==k)
        {
            return arr[p];
        }
        else if(p>k)
        {
            high=p-1;
        }
        else
        {
            low=p+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int kth;
    cin>>kth;
    cout<<Quick_Select(arr,n,kth-1)<<endl;

    return 0;
}