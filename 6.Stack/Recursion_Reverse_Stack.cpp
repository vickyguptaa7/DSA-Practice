#include<iostream>
#include<stack>

using namespace std;

void Display(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void push_at_bottom(stack<int> &st,int val)
{
    if(st.empty())
    {
        st.push(val);
        return;
    }
    int data=st.top();
    st.pop();
    push_at_bottom(st,val);
    st.push(data);
}

void RReverse(stack<int> &st)
{
    if(st.empty())return;
    int val=st.top();
    st.pop();    
    RReverse(st);
    push_at_bottom(st,val);
}
int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    Display(st);

    RReverse(st);

    Display(st);
    return 0;
}