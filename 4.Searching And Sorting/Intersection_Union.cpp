#include<iostream>
using namespace std;

void Union(int a1[],int a2[],int n,int m)
{
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(i>0&&a1[i]==a1[i-1]) {i++;continue;}
        if(j>0&&a2[j]==a2[j-1]) {j++;continue;}
        if(a1[i]==a2[j])
        {
            cout<<a1[i]<<" ";
            i++;j++;
        }
        else if(a1[i]>a2[j])
        {
            cout<<a2[j]<<" ";
            j++;
        }
        else 
        {
            cout<<a1[i]<<" ";
            i++;
        }
    }
    while(i<n)
    {
        if(i>0&&a1[i]==a1[i-1]) {i++;continue;}
        cout<<a1[i]<<" ";
        i++;
    }

    while(j<m)
    {
        if(j>0&&a2[j]==a2[j-1]) {j++;continue;}
        cout<<a2[j]<<" ";
        j++;
    }
    
}

void Intersection(int a1[],int a2[],int n,int m)
{
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(i>0&&a1[i]==a1[i-1]) {i++;continue;}
        if(a1[i]==a2[j])
        {
            cout<<a1[i]<<" ";
            i++;j++;
        }
        else if(a1[i]>a2[j])
        {
            j++;
        }
        else 
        {
            i++;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a1[n],a2[m];
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>a2[i];
    }

    Intersection(a1,a2,n,m);
    cout<<endl;
    Union(a1,a2,n,m);
    return 0;
}