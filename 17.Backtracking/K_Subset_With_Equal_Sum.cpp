#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void K_Subset(vector<int>arr,int sum,int k,vector<vector<int>>&res,vector<int>ans)
{
    if(sum==0)
}

bool K_Subset_With_Equal_Sum(vector<int>arr,int n,int k,vector<vector<int>>&res)
{
    if(k==0||k==1)
    {
        res.push_back(arr);
        return k;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%k!=0)return 0;
    else 
    {
        vector<int>ans;
        K_Subset(arr,0,k,res,ans);
    }
    return 1;
}

void Print(vector<vector<int>>res)
{
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<vector<int>>res;
    if(K_Subset_With_Equal_Sum(arr,n,k,res))
    {
        Print(res);
    }
    else
    {
        cout<<"Not Possible"<<endl;
    }
    return 0;
}