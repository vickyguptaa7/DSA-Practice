#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> vec, int i,int j,int k)
{
    while(j>=i)
    {
        int mid=i+(j-i)/2;
        if(vec[mid]==k)
        {
            return mid;
        }
        else if(vec[mid]>k)
        {
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
    }
    return -1;
}
int Search(vector<int> arr, int K) {
    int i=0,n=arr.size();
    int j=n-1,midans=-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(mid>0&&mid<n-1)
        {
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
            {
                midans=mid;
                break;
            }
            else if(arr[mid-1]<arr[mid+1])
            {
                i=mid+1;
            }
            else 
            j=mid-1;
        }
        if(mid==0)
        {
            if(arr[mid]>arr[mid+1])
            midans=0;
            else 
            midans=1;
            break;
        }
        if(mid==n-1)
        {
            if(arr[mid-1]<arr[mid])
            midans=mid;
            else
            midans=mid-1;
            break;
        }
    }
    if(arr[0]<=K&&arr[midans]>=K)
    {
        return BinarySearch(arr,0,midans,K);
    }
    else
    return BinarySearch(arr,midans+1,n-1,K);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Search(arr,10)<<endl;;
    return 0;
}