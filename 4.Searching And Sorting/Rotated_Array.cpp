#include <iostream>
using namespace std;

int Binary_Search(int arr[],int i,int j,int target)
{
    while(j>=i)
    {
        int mid=(i+j)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]>target)
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

int Find(int arr[], int n,int target) // T.C -> O(logn)  2 Iteration Are Required
{
    int i=0,j=n-1;
    while(j>=i)
    {
        int mid=(i+j)/2;
        if(arr[mid]<arr[j])
        {
            j=mid;
        }
        else
        {
            i=mid+1;
        }
    }
    if(target<=arr[n-1])
    {
        return Binary_Search(arr,j,n-1,target);
    }
    else
    {
        return Binary_Search(arr,0,j-1,target);
    }
}

int Rotated_Target(int arr[],int n,int target) 
{
    int i=0,j=n-1;
    while(j>=i)
    {
        int mid=(i+j)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<arr[j])
        {
            if(target>arr[mid]&&target<=arr[j])
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        else
        {
            if(target>=arr[i]&&target<arr[mid])
            {
                j=mid-1;
            }    
            else
            {
                i=mid+1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int target;
    cin>>target;

    cout << Find(arr, n,target) << endl;

    return 0;
}