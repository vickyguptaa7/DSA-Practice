#include<iostream>
#include<algorithm>
using namespace std;

void Merge(int a1[],int n,int a2[],int m)
{
    int i=0,j=0,k=n-1;

    while(i<=k&&j<m)
    {
        if(a1[i]>=a2[j])
        {
            int temp=a2[j];
            a2[j]=a1[k];
            a1[k]=temp;
            k--;
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(a1,a1+n);
    sort(a2,a2+m);
}

int main(){
    int n,m;
    cin>>n>>m;
    
    int *a1=new int[n];
    int *a2=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>a2[i];
    }
    

    Merge(a1,n,a2,m);
    
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