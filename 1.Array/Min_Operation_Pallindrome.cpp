#include<iostream>
using namespace std;

int Min_Operation(int *arr,int n)
{
    int Opertn=0;
    int i=0,j=n-1;
    while(i<=j)
    {
        if(arr[i]==arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i]>arr[j])
        {
            arr[j-1]+=arr[j];
            j--;
            Opertn++;
        }
        else{
            arr[i+1]+=arr[i];
            i++;
            Opertn++;
        }
    }
    return Opertn;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Min_Operation(arr,n)<<endl;
    return 0;
}