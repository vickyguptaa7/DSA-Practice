#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int Max=INT_MIN;

    for(int i=n-1;i>=0;i--)
    {
        if(Max<arr[i])
        {
            cout<<arr[i]<<" ";
            Max=arr[i];
        }
    }
    cout<<endl;
    return 0;
}