#include<iostream>
using namespace std;

int Missing_Term(int arr[],int n)
{
    if(n<=2)return -1;

    int d=(arr[n-1]-arr[0])/n;
    
    int i=0,j=n-1;

    while(j>=i)
    {
        int mid=(i+j)/2;
        
        if(arr[mid]+d!=arr[mid+1])return (arr[mid]+d);
        if(arr[mid]-d!=arr[mid-1])return (arr[mid]-d);

        if(arr[i]!=arr[mid]-(mid-i)*d)
        {
            j=mid+1;
        }
        else
        {
            i=mid+1;
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

    cout<<Missing_Term(arr,n)<<endl;
    return 0;
}