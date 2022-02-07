#include<iostream>
using namespace std;

void Merge(int Arr[],int s,int m,int n)
{
    int p=m-s+1, q=n-m;
    int *Arr_1=new int[p];
    int *Arr_2=new int[q];

    for(int i=0;i<p;i++)
    {
        Arr_1[i]=Arr[i+s];
    }
    
    for(int i=0;i<q;i++)
    {
        Arr_2[i]=Arr[i+m+1];
    }

    int x=0,y=0,z=s;

    while(p>x&&q>y)
    {
        if(Arr_1[x]>Arr_2[y])
        {
            Arr[z]=Arr_2[y];
            y++;
            z++;
        }
        else
        {
            Arr[z]=Arr_1[x];
            x++;
            z++;
        }
    }

    while(p>x)
    {
        Arr[z]=Arr_1[x];
            x++;
            z++;
    }
    while(q>y)
    {
      Arr[z]=Arr_2[y];
            y++;
            z++; 
    }
    
}

void Merge_Sort(int Arr[],int s,int n)
{
    if(n>s)
    {
        int mid=(n+s)/2;
        
        Merge_Sort(Arr,s,mid);
        Merge_Sort(Arr,mid+1,n);

        Merge(Arr,s,mid,n);
    }
}

void Swap(int Arr[],int i,int j)
{
    int temp=Arr[i];
    Arr[i]=Arr[j];
    Arr[j]=temp;
}

int Partition_Index(int Arr[],int s,int n)
{
    int Partition=Arr[n];
    
    int j=s-1;
    for(int i=s;i<n;i++)
    {
        if(Partition>Arr[i])
        {
            j++;
            Swap(Arr,i ,j);
        }
    }
    Swap(Arr,j+1,n);
    return j+1;
}

void Quick_Sort(int Arr[],int s,int n)

{
    if(n>s)
    {
        int Partition=Partition_Index(Arr,s,n);
        
        Quick_Sort(Arr,s,Partition-1);

        Quick_Sort(Arr,Partition+1,n);
    }
}

void Sort(int Arr[],int n) // Time Complexity Is O(n^2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(Arr[i]>Arr[j])
            {
                int temp=Arr[i];
                Arr[i]=Arr[j];
                Arr[j]=temp;
            }
        }
    }
}

int KthSmallest(int arr[],int n,int k)
{
    Quick_Sort(arr,0,n);
    int ans=arr[n-1];
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]!=arr[i])
        {
            k--;
        }
        if(k==0)
        {
            ans=arr[i-1];
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<KthSmallest(arr,n,k);
    return 0;
}