#include<iostream>
#include<unordered_map>
#define  Max 10000
using namespace std;


int Max_Freq_Brute(int l[],int r[],int n) //brute T.C-> O(n^2*m) where m is the Max Range
{
    pair<int,int>answer={0,0};
    for(int i=0;i<n;i++)
    {
        int strt=l[i];
        int stop=r[i];
        while(strt<=stop)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(strt>=l[j]&&strt<=r[j])
                {
                    count++;
                }
            }
            if(answer.second<count)
            {
                answer={strt,count};
            }
            strt++;
        }
    }
    return answer.first;
}

int Max_Freq_Better(int l[],int r[],int n)// T.C->O(m*n)
{
    pair<int,int>answer={0,0};
    unordered_map<int,int>umap;
    for(int i=0;i<n;i++)
    {
        int strt=l[i];
        int stop=r[i];
        while(strt<=stop)
        {
            umap[strt]++;
            auto x=umap.find(strt);
            if(answer.second<x->second)
            {
                answer={x->first,x->second};
            }
            strt++;
        }
    }
    return answer.first;
}

int Max_Freq_Optimal(int l[],int r[],int n) 
{
    int arr[Max]={0};
    
    for(int i=0;i<n;i++)
    {
        arr[l[i]]=1;
        arr[r[i]+1]=-1;
    }
    int answer=0;
    for(int i=1;i<Max;i++)
    {
        arr[i]+=arr[i-1];
        if(arr[answer]<arr[i])
        {
            answer=i;
        }
    }
    return answer;

}

int main(){
    int n;
    cin>>n;
    int l[n],r[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }   
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }   
    
    cout<<Max_Freq_Optimal(l,r,n);

    return 0;
}