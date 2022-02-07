#include<iostream>
#include<unordered_map>
using namespace std;

int Largest_Common_Subarray(int arr[],int brr[],int n) //brute;
{
    int Max=0;
    for(int i=0;i<n;i++)
    {
        int sum1=0,sum2=0;
        for(int j=i;j<n;j++)
        {
            sum1+=arr[j];
            sum2+=brr[j];
            if(sum1==sum2)
            {
                Max=max(Max,j-i+1);
            }
        }
    }
    return Max;
}

int Largest_Common_Subarray_O(int arr[],int brr[],int n) // Optimal
{
    int *newarr=new int[n];  // Little Trick
    for(int i=0;i<n;i++)
    {
        newarr[i]=arr[i]-brr[i];
    }
    unordered_map<int,int>umap;
    int presum=0;
    int Max=0;
    for(int i=0;i<n;i++) // Code Of The Longest Subarray With 0 Sum
    {
        presum+=newarr[i];
        
        if(presum==0)
        {
            Max=max(Max,i+1);
        }
        auto x=umap.find(presum);
        if(x!=umap.end())
        {
            Max=max(Max,i-x->second);
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
    int *brr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    
    cout<<Largest_Common_Subarray_O(arr,brr,n);

    return 0;
}