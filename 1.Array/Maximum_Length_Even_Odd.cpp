#include<iostream>
using namespace std;

int Max_Len(int arr[],int n)
{
    int Max=1,count=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]%2==arr[i]%2)
        {
            count=1;
        }
        else
        {
            count++;
        }
        Max=max(Max,count);
    }
    return Max;
}

int Max_Length(int arr[],int n) // T.C O(n^2)
{
    int Max=1;
    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]%2==arr[j-1]%2)
            {
                break;
            }
            else 
            {
                count++;
            }
        }
         Max=max(count,Max);
    }
    return Max;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Max_Len(arr,n)<<endl;

    return 0;
}