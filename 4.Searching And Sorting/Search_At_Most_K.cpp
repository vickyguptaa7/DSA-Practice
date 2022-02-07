#include<iostream>
using namespace std;

int Search(int arr[],int n,int d,int key)
{
    int i=0;
    while(i<n)
    {
        if(arr[i]==key)return i;
        int jump=abs(key-arr[i]);
        jump=max(1,jump/d);
        i+=jump;
    }
    return -1;
}

int main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<Search(arr,n,d,key)<<endl; 
    return 0;
}