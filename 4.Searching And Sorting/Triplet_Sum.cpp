#include<iostream>
using namespace std;

int Triplet(int arr[],int n,int k)
{
    int count=0;
    for(int i=0;i<n-2;i++)
    {
        int j=i+1,z=n-1;
        while(j<z)
        {
            if(arr[i]+arr[j]+arr[z]<k)
            {
                count+=z-j;
                j++;
            }
            else
            {
                z--;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<Triplet(arr,n,k)<<endl;
    return 0;
}   