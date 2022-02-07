#include<iostream>
#include<unordered_map>
using namespace std;

int Largest_Subarray_Sum_K(int arr[],int n,int key)
{
    unordered_map<int,int> umap;
    int psum=0;
    int Max=0;
    for(int i=0;i<n;i++)
    {
        psum+=arr[i];
        auto x=umap.find(psum-key);
        if(x!=umap.end())
        {
            Max=max(i-x->second,Max);
        }
        if(psum==key)
        {
            Max=max(Max,i+1);
        }
        if(umap.find(psum)==umap.end())
        umap.insert({psum,i});
    }
    return Max;
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
    cout<<Largest_Subarray_Sum_K(arr,n,key)<<endl;
    return 0;
}