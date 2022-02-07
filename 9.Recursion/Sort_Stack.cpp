#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int>&st,int val)
{
    if(st.empty()||st.top()<=val)
    {
        st.push(val);
        return;
    }
    int data=st.top();
    st.pop();
    InsertAtBottom(st,val);
    st.push(data);
}

void Sort_Stack(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }
    int val=st.top();
    st.pop();
    Sort_Stack(st);
    InsertAtBottom(st,val);
}

void Display(stack<int>st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(0);
    st.push(2);
    
    Display(st);

    Sort_Stack(st);

    Display(st);
    return 0;
}