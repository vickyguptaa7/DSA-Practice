#include<iostream>
#include<deque>
using namespace std;

int* Maximum_In_K(int arr[],int n,int k)
{
    int *ans=new int[n-k+1];
    deque<int>dq;
    int i=0,j=0;
    while(j<n)
    {
        if(dq.empty())dq.push_front(j);
        else
        {
            if(arr[dq.front()]<=arr[j])
            {
                while(!dq.empty())dq.pop_front();
                dq.push_front(j);
            }
            else if(dq.back()<=arr[j])
            {
                while(arr[dq.back()]<=arr[j])dq.pop_back();
                dq.push_back(j);
            }
            else
            dq.push_back(j);
        }
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            ans[i]=arr[dq.front()];
            if(dq.front()==i)
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int*ans=Maximum_In_K(arr,n,k);

    for(int i=0;i<=n-k;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}