#include<iostream>
#include<unordered_set>
using namespace std;

void Pair_Sum(int arr[],int n,int key)
{
    unordered_set<int> uset; 
    for(int i=0;i<n;i++)
    {
        if(uset.find(key-arr[i])!=uset.end())
        cout<<arr[i]<<" "<<key-arr[i]<<endl;
        uset.insert(arr[i]);
    }
}

int main(){
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    int key;
    cin>>key;
    Pair_Sum(arr,n,key);
    return 0;
}