#include<iostream>
using namespace std;

int Kth_Element(int arr1[],int arr2[],int n,int m,int Kth)
{
    if(Kth<=0||Kth>(m+n))return -1;
    // if(m>n)
    // {
    //     return Kth_Element(arr2,arr1,m,n,Kth);
    // }

    int low=0,high=n;
    while(low<=high)
    {
        int mid1=low+(high-low)/2;
        int mid2=Kth-mid1;
        if(mid2<0){high=mid1-1;continue;}
        if(mid2>m){low=mid1+1;continue;}

        int min1=(mid1!=n)?arr1[mid1]:INT_MAX;
        int max1=(mid1!=0)?arr1[mid1-1]:INT_MIN;

        int min2=(mid2!=m)?arr2[mid2]:INT_MAX;
        int max2=(mid2!=0)?arr2[mid2-1]:INT_MIN;

        if(min1>=max2&&min2>=max1)
        {
            return (max(max1,max2));
        }
        else if(max1>min2)
        {
            high=mid1-1;
        }
        else
        {
            low=mid1+1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int kth;
    cin>>kth;

    cout<<Kth_Element(arr1,arr2,n,m,kth)<<endl;
    return 0;
}