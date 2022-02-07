#include<iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};

void Max_Min_Less_Compare_Brute_Force(int *arr,int n) // Max And Min Comparision - 2(n-1)
{
    int Max=arr[0];
    int Min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>Max)
        {
            Max=arr[i];
        }
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]<Min)
        {
            Min=arr[i];
        }
    }
    
    cout<<Min<<" "<<Max<<endl;
}

void Max_Min_Less_Compare_Other(int arr[],int n) // Maximum Comaparision 2(n-1) And Minimum (n-1)
{
    int Max=arr[0];
    int Min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>Max)
        {
            Max=arr[i];
        }
        else if(arr[i]<Min)
        {
            Min=arr[i];
        }
    }
    cout<<Min<<" "<<Max<<endl;
}

void Max_Min_Less_Compare_Pair_Optimal(int arr[],int n)// Max  Comparision (3n/2)-1 And Min Comparision (3n/2)-2
{
    int Max,Min,i;
    if(n%2)
    {
        Max=arr[0];
        Min=arr[0];
        i=1;
    }
    else
    {
        if(arr[0]>arr[1])
        {
            Max=arr[0];
            Min=arr[1];
        }
        else
        {
            Max=arr[1];
            Min=arr[0];
        }
        i=2;
    }

    for(i;i<n;i=i+2)
    {
        if(arr[i+1]>arr[i])
        {
            if(arr[i+1]>Max)
            {
                Max=arr[i+1];
            }
            if(arr[i]<Min)
            {
                Min=arr[i];
            }
        }
        else
        {
            if(arr[i]>Max)
            {
                Max=arr[i];
            }
            if(arr[i+1]<Min)
            {
                Min=arr[i+1];
            }
        }
    }
    cout<<Min<<" "<<Max<<endl;
}

Pair Max_Min_Less_Compare_Tournament(int arr[],int s,int n)
{
    Pair minmax,mmr,mml;
    
    if(s==n)
    {
        minmax.min=arr[s];
        minmax.max=arr[s];
        return minmax;
    }
    if(n==s+1)
    {
            if(arr[s+1]>arr[s])
            {
                minmax.max=arr[s+1];
                minmax.min=arr[s];
            }
            else
            {
                minmax.max=arr[s];
                minmax.min=arr[s+1];
            }
            return minmax;
    }
 
        int mid=s+(n-s)/2;
        mml=Max_Min_Less_Compare_Tournament(arr,s,mid);
        mmr=Max_Min_Less_Compare_Tournament(arr,mid+1,n);
        if(mmr.max>mml.max)
        {
            minmax.max=mmr.max;
        }
        else
        {
            minmax.max=mml.max;
        }
        if(mmr.min>mml.min)
        {
            minmax.min=mml.min;
        }
        else
        {
            minmax.min=mmr.min;
        }
    return minmax;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    Pair minmax=Max_Min_Less_Compare_Tournament(arr,0,n-1);
    
    cout<<minmax.min<<" "<<minmax.max<<endl;

    return 0;
}