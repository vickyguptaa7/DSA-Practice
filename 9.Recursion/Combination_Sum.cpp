#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int Combination_Subseq(int arr[],int idx,int n,int sum)
{
    if(idx==n)
    {
        if(sum==0)return 1;
        else return 0;
    }

    int cnt=Combination_Subseq(arr,idx+1,n,sum);
    if(sum>0)
    {
        cnt+=Combination_Subseq(arr,idx,n,sum-arr[idx]);
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Combination_Subseq(arr,0,n,6)<<endl;
    return 0;
}