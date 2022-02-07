#include<iostream>
#include<unordered_set>
using namespace std;

bool Subarray_Zero_Sum(int arr[],int n)
{
    unordered_set<int>uset;
    int presum=0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(uset.find(presum)!=uset.end())
        {
            return true;
        }
        if(presum==0)return true;
        uset.insert(presum);
    }
    return false;
}

int main(){
    
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Subarray_Zero_Sum(arr,n)<<endl;
    return 0;
}