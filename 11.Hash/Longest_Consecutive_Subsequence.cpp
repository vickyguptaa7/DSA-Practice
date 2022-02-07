#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int Longest_Consecutive_Subsequence_B(int arr[],int n) //brute
{
    sort(arr,arr+n);
    int count=1,Max=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]+1==arr[i])
        {
            count++;
        }
        else
        {
            Max=max(Max,count);
            count=1;
        }
    }
    Max=max(Max,count);
    return Max;
}

int Longest_Consecutive_Subsequence_O(int arr[],int n) //Omptimal
{
    unordered_set<int>uset;
    for(int i=0;i<n;i++)
    {
        uset.insert(arr[i]);
    }
    int count=1,Max=0;
    for(int i=0;i<n;i++)
    {
        if(uset.find(arr[i]-1)==uset.end())
        {
            while(uset.find(arr[i]+count)!=uset.end())
            {
                count++;
            }
            Max=max(Max,count);
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
    cout<<Longest_Consecutive_Subsequence_O(arr,n);
    return 0;
}