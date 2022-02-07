#include<iostream>

using namespace std;

void Swap(int a1[],int a2[],int i,int j=0)
{
    int temp=a1[i];
    a1[i]=a2[j];
    a2[j]=temp;
}

void Sort(int a2[],int m)
{
    for(int i=1;i<m;i++)
    {
        if(a2[i-1]>=a2[i])
        {
            int temp=a2[i-1];
            a2[i-1]=a2[i];
            a2[i]=temp;
        }
        else 
        {
            break;
        }
    }
}

void Merge_Sorted_Array(int arr1[],int arr2[],int n,int m) // Time Complexity In Worst Case O(n^2)
{
    for(int i=0;i<n;i++)
    {
        if(arr1[i]>arr2[0])
        {
            Swap(arr1,arr2,i);
            Sort(arr2,m);
        }
    for(int j=0;j<n;j++)
    {
        cout<<arr1[j]<<" ";
    }
    cout<<endl;
    for(int j=0;j<m;j++)
    {
        cout<<arr2[j]<<" ";
    }
    cout<<endl<<endl<<endl;
    }
}

void Merge(int arr[],int i,int mid,int n)
{
    int p=mid-i+1,q=n-mid;
    int arr1[p],arr2[q];

    for(int j=0;j<p;j++)
    {
        arr1[j]=arr[i+j];
    }
    for(int j=0;j<q;j++)
    {
        arr2[j]=arr[mid+1+j];
    }

    int x=0,y=0,z=i;
    while(p>x&&q>y)
    {
        if(arr1[x]>arr2[y])
        {
            arr[z]=arr2[y];
            y++;z++;
        }
        else
        {
            arr[z]=arr1[x];
            x++;z++;
        }
    }
    while(p>x)
    {
        arr[z]=arr1[x];
            x++;z++;
    }
    while(q>y)
    {
        arr[z]=arr2[y];
            y++;z++;
    }
    
}

void Merge_Sort(int arr[],int i,int n)
{
    if(n>i)
    {
        int mid=(i+n)/2;
        Merge_Sort(arr,i,mid);
        Merge_Sort(arr,mid+1,n);

        Merge(arr,i,mid,n);
        
    }
}

void Merge_Array(int arr1[],int arr2[],int n,int m)
{
    int x=0,y=0,k=n-1;
    while(k>x)
    {
        if(arr1[x]<=arr2[y])
        {
            x++;
        }
        else
        {
             Swap(arr1,arr2,k,y);
             k--;
             y++;
        }
    }
    Merge_Sort(arr1,0,n);
    Merge_Sort(arr2,0,m);
}

int main(){
    int n,m;
    cin>>n>>m;
    int *a1=new int[n];
    int *a2=new int[m];
    
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>a2[i];
    }

    Merge_Array(a1,a2,n,m);

    for(int i=0;i<n;i++)
    {
        cout<<a1[i]<<" ";
    }
    
    for(int i=0;i<m;i++)
    {
        cout<<a2[i]<<" ";
    }
    cout<<endl;

    return 0;
}