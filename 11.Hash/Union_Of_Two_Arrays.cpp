#include<iostream>
#include<unordered_set>
using namespace std;

int Union(int *arr,int *brr,int n,int m)
{
    unordered_set<int>hashset;
    
    for(int i=0;i<n;i++)
    {
        hashset.insert(arr[i]);        
    }
    for(int i=0;i<m;i++)
    {
        hashset.insert(brr[i]);        
    }
    return hashset.size();
}

int main(){
    int n,m;
    cin>>n>>m;

    int *arr=new int[n];
    int *brr=new int[m];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
    }
    
    cout<<Union(arr,brr,n,m)<<endl;
    return 0;
}