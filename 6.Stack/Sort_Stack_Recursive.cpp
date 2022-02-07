#include<iostream>
#include<stack>
using namespace std;

void Place_At_Correct_Position(stack<int>&st,int num)
{
    if(st.empty()||st.top()<=num)
    {
        st.push(num);
        return;
    }
    int val=st.top();
    st.pop();
    Place_At_Correct_Position(st,num);
    st.push(val);
}

void Sort_Stack(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }
    int num=st.top();
    st.pop();
    Sort_Stack(st);
    Place_At_Correct_Position(st,num);
}

void Display(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
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

    Sort_Stack(st);
    Display(st);
    return 0;
}