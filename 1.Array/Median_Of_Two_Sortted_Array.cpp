#include<iostream>
using namespace std;

int Median(int *arr1,int *arr2,int n,int m)
{
    int len=m+n;
    int i;
    (len%2==0)?i=2:i=1;
    
    int Max=0;
    for(int j=0;j<i;j++)
    {
        int p=0,q=0;
        int count=0;
        while((count!=len/2)||(count!=(len/2)-1)&&i==1)
        {
            if(arr1[p]<arr2[q])
            {
                p++;
                count++;
            }
            else{
                q++;
                count++;
            }
        }
    }

    while()
}

int main(){
    int n,m;
    cin>>n>>m;

    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    cout<<Median(arr1,arr2,n,m)<<endl;
    return 0;
}