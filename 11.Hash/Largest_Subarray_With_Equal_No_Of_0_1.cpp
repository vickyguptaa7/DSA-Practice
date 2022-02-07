#include<iostream>
#include<unordered_map>
using namespace std;

int Largest_Subarray_Wiht_Equal_One_Zero(int arr[],int n)
{
    unordered_map<int,int>umap;
    int presum=0;
    int Max=0;
    for(int i=0;i<n;i++)
    {
        presum+=(arr[i]==0)?-1:1;
        auto x=umap.find(presum);
        if(x!=umap.end())
        {
            Max=max(Max,i-x->second);
        }
        if(presum==0)
        {
            Max=max(Max,i+1);
        }
        if(umap.find(presum)==umap.end())
        {
            umap.insert({presum,i});
        }
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

    cout<<Largest_Subarray_Wiht_Equal_One_Zero(arr,n)<<endl;
    return 0;
}