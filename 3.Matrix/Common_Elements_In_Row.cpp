#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Common_Element_Brute(int **arr,int n,int m)
{
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        bool check_1=true;
        for(int j=0;j<n;j++)
        {
            bool check_2=false;
            for(int k=0;k<n;k++)
            {
                if(arr[0][i]==arr[j][k])
                {
                    check_2=true;
                    break;
                }
            }
            if(!check_2)
            {
                check_1=false;
                break;
            }
        }
        if(check_1)
        {
            ans.push_back(arr[0][i]);
        }
    }
    return ans;
}

bool Binary_Search(int arr[],int n,int key)
{
    int low=0,high=n-1;
    while(high>=low)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            return 1;
        }
        else if(arr[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return 0;
}

vector<int>Common_Element_Better(int **arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        sort(arr[i],arr[i]+m);
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        bool check=true;
        for(int j=1;j<n;j++)
        {
            if(!Binary_Search(arr[j],m,arr[0][i]))
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            ans.push_back(arr[0][i]);
        }
    }
    return ans;
}

int Common_Element_Better_Better(int **arr,int n,int m)
{
    int tarr[n]={m-1};
    int minele=0;
    for(int j=1;j<n;j++)
    {
        if(arr[j][tarr[j]]<arr[j-1][tarr[j-1]])
        {
            minele=j;
        }
    }
    while(true)
    {

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<int>ans=Common_Element_Better(arr,n,m);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}