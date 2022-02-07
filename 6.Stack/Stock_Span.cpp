#include<iostream>
#include<stack>
using namespace std;

int* Stock_Span(int arr[],int n)
{
    stack<int>st;
    int*ans=new int[n];
    for(int i=0;i<n;i++)
    {
        while (!st.empty()&&arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        if(st.empty())ans[i]=1;
        else 
        ans[i]=i-st.top();
        st.push(i);
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

    int *ans=Stock_Span(arr,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}