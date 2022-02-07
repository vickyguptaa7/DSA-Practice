#include<iostream>
using namespace std;

int First_Index(int arr[],int n)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(arr[mid]==1&&arr[mid-1]!=1)
        {
            return mid;
        }
        else if(arr[mid]<1)
        {
            i=mid+1;
        }
        else 
        {
            j=mid-1;
        }
    }
    return -1;
}

int Max_1(int **arr,int n,int m)
{
    int Max=-1,row=-1;
    for(int i=0;i<n;i++)
    {
        int idx=First_Index(arr[i],m);
        int No_1=m-idx;
        if(Max<No_1&&idx!=-1)
        {
            Max=No_1;
            row=i;
        }
    }
    return row;
}

int Max_One(int **arr,int n,int m)
{
    int Max=0,row=-1;
    for(int i=0;i<n;i++)
    {
        int count;
        (Max==0)?count=0:count=Max;
        for(int j=m-1-Max;j>=0;j--)
        {
            if(arr[i][j]==1)
            {
                count++;
            }
            else{
                break;
            }
        }
        if(Max<count)
        {
            Max=count;
            row=i;
        }
    }
    return row;
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
    
    cout<<Max_One(arr,n,m)<<endl;

    return 0;
}