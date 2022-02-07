#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];

    int count=0;
    for(int i=0;i<n-2;i++)
    {
        int k=i+2;
        for(int j=i+1;j<n-1;j++)
        {
            while(k<n&&arr[j]+arr[i]>arr[k])
            {
                k++;
            }
            if(k>j)
            {
                count+=k-j-1;
                
            }
        }
    }
    cout<<count;
    return 0;
}