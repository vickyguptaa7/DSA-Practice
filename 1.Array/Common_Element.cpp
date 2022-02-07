#include<iostream>
#include<vector>
using namespace std;

void Common(int *arr1,int *arr2,int *arr3,int p,int q,int r)// Fails For Similar Element
{
    for(int i=0;i<p;i++)
    {
        bool chk=true;
        for(int j=0;j<q;j++)
        {
            if(arr1[i]<arr2[j]){
                break; chk=false;
                }
            else if(arr1[i]==arr2[j])
            {
                break;
            }
        }
        if(chk)
        for(int k=0;k<r;k++)
        {
            if(arr1[i]==arr3[k])
            {
                cout<<arr1[i]<<" ";
            }
        }
    }
}

void Com_Element(int *arr1,int *arr2,int *arr3,int p,int q,int r) // T.C O(N) And Space Complexity O(N)
{
    int i=0,j=0;
    vector<int> similar;

    while(p>i&&q>j)
    {
        if(arr1[i]==arr2[j])
        {
            similar.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
        else 
        {
            i++;
        }
    }

    i=0;j=0;
    while(r>i&&similar.size()>j)
    {
        if(arr3[i]==similar[j])
        {
            cout<<arr3[i]<<" ";
            i++;
            j++;
        }
        else if(arr3[i]>similar[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

void C_Element(int *arr1,int *arr2,int *arr3,int p,int q,int r)
{
    int i=0,j=0,k=0;

    while(p>i&&q>j&&r>k)
    {
        if(arr1[i]==arr2[j]&&arr2[j]==arr3[k])
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(arr1[i]>arr2[j]||arr3[k]>arr2[j])
        {
            j++;
        }
        else if(arr1[i]>arr3[k]||arr2[j]>arr3[k])
        {
            k++;
        }
        else 
        {
            i++;
        }
    }
}

int main(){
    int p,q,r;
    cin>>p>>q>>r;
    int arr1[p];
    int arr2[q];
    int arr3[r];

    for(int i=0;i<p;i++)
    {
        cin>>arr1[i];
    }

    for(int i=0;i<q;i++)
    {
        cin>>arr2[i];
    }
    
    for(int i=0;i<r;i++)
    {
        cin>>arr3[i];
    }

    C_Element(arr1,arr2,arr3,p,q,r);

    return 0;
}