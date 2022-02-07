#include<iostream>
#include<unordered_map>
using namespace std;

int Xor_Subarray_Brute(int arr[],int n,int m)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        int Xor=0;
        for(int j=i;j<n;j++)
        {
            Xor=(Xor^arr[j]);
            if(Xor==m)
            {
                count++;
            }
        }
    }
    return count;
}

int Xor_Subarray_Optimal(int arr[],int n,int m)
{
    unordered_map<int,int>umap;
    int count=0;
    int prexor=0;
    for(int i=0;i<n;i++)
    {
        prexor=(prexor^arr[i]);
        if(umap.find(prexor^m)!=umap.end())
        {
            count+=umap[prexor^m];
        }
        if(prexor==m)count++;
        umap[prexor^m]++;
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
    int m;
    cin>>m;
    cout<<Xor_Subarray_Optimal(arr,n,m)<<endl;

    return 0;
}