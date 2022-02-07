#include<iostream>
#include<unordered_set>
using namespace std;

bool Subarray_Sum_K(int *arr,int n,int key)
{
    unordered_set<int> uset;
    int presum=0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(uset.find(presum-key)!=uset.end())
        {
            return true;
        }
        if(presum==key)
        {
            return true;
        }
        uset.insert(presum);
    }
    return false;
}
// 1 3 6 10 15
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
    cout<<Subarray_Sum_K(arr,n,key)<<endl;
    return 0;
}