#include<iostream>
using namespace std;

char Next_Element(char arr[],int n,char k)
{
    int i=0,j=n-1;
    char ans='#';
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(arr[mid]>k)
        {
            ans=arr[mid];
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    char k;
    cin>>k;
    cout<<Next_Element(arr,n,k)<<endl;
    return 0;
}