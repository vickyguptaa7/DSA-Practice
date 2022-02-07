#include<iostream>
#include<stack>

using namespace std;

int Middle_Element(stack<int>st,int n,int curr=0)
{
    if(curr==n/2)
    {
        return (st.size()==0)?-1:st.top();
    }
    int val=st.top();
    st.pop();
    int mid=Middle_Element(st,n,curr+1);
    st.push(val);
    return mid;
}

int main(){
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        st.push(num);
    }
    cout<<Middle_Element(st,n);
    return 0;
}