#include<iostream>
using namespace std;

int Max_Consec(bool *arr,int n)
{
    int count=0,Max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            count=0;
        }
        else
        {
            count++;
        }
        Max=max(Max,count);
    }
    return Max;
}

int main(){
    int n;
    cin>>n;
    bool arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Max_Consec(arr,n)<<endl;
    return 0;
}