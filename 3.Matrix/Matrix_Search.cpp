#include<iostream>
using namespace std;

bool Search(int **arr,int n,int m,int target) // T.C - O(n^2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==target)
            {
                return 1;
            }
        }
    }
    return 0;
}

bool Search_Binary(int **arr,int n,int m,int target)
{
    for(int i=0;i<n;i++)
    {
        int p=0,q=m-1;
        while(p<=q)
        {
            int mid=(p+q)/2;
            if(arr[i][mid]==target)
            {
                return 1;
            }
            else if(arr[i][mid]>target)
            {
                q=mid-1;
            }
            else 
            {
                p=mid+1;
            }
        }
    }
    return 0;
}

bool Search_Optimum(int **arr,int n,int m,int target) // Optimal Approach If Rows Are In Sorted Only
{
    int i=0,j=m-1;
    
    while(i<n&&j>=0)
    {
        if(arr[i][j]==target)
        {
            return 1;
        }
        else if(arr[i][j]>target)
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
    return 0;
}

bool Search_Opt(int **arr,int n,int m,int target)// Optimal Approach if rows and column both are in sorted Manner
{// T.C - log(mn)  And  S.C - O(1)
    
    int i=0,j=m*n-1;

    while(i<=j)
    {
        int mid=(i+j)/2;
        int rem=mid%m;
        int Dev=mid/m;

        if(arr[Dev][rem]==target)
        {
            return 1;
        }
        else if(arr[Dev][rem]>target)
        {
            j=mid-1;
        }
        else 
        {
            i=mid+1;
        }
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];

    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    cout<<endl;

    cout<<Search_Opt(arr,n,m,target);
    return 0;
}