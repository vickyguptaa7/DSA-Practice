#include<iostream>
#include<stack>
using namespace std;

struct minStack
{
    stack<int> st;
    int min;
    void push(int val)
    {
        if(st.empty())
        {
            st.push(val);
            min=val;
            return;
        }
        if(val>min)
        {
            st.push(val);
        }
        else
        {
            st.push(2*val-min);
            min=val;
        }
    }
    void pop()
    {
        if(st.empty())
        {
            cout<<"Stack Is Empty"<<endl;
            return;
        }
        if(st.top()>min)st.pop();
        else
        {
            min=2*min-st.top();
            st.pop();
        }
    }
    int top()
    {
        if(st.empty())
        {
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return (st.top());
    }
    int getmin()
    {
        if(st.empty())
        {
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return min;
    }
    int size()
    {
        return (st.empty())?0:st.size();
    }
};

int main(){
    minStack st;
    st.push(0);
    st.push(5);
    st.push(2);
    st.push(-1);
    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.getmin()<<endl;    
    st.pop();
    cout<<st.getmin()<<endl; 
    
    
    return 0;
}