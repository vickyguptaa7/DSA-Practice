#include<iostream>
#include<unordered_set>
using namespace std;

int Intersection(int *arr,int *brr,int n,int m)
{
    unordered_set<int>hashset;
    
    for(int i=0;i<n;i++)
    {
        hashset.insert(arr[i]);        
    }
    int count=0;
    for(int i=0;i<m;i++)
    {
        if(hashset.find(brr[i])!=hashset.end())
        {
            count++;
            hashset.erase(arr[i]);
        }
    }
    return count;
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
    
    cout<<Intersection(arr,brr,n,m)<<endl;
    return 0;
}