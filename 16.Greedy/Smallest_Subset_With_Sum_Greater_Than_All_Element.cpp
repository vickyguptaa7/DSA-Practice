#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int Smallest_Subset_Greater_Sum(int arr[],int n)
{
    int len=INT_MAX;
    int arr_sum=0,half_sum=0;
    for(int i=0;i<n;i++)arr_sum+=arr[i];
    half_sum=arr_sum/2;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(len>=(j-i+1)&&half_sum<sum)
            {
                len=j-i+1;
            }
        }
    }
    return len;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Smallest_Subset_Greater_Sum(arr,n)<<endl;
    return 0;
}