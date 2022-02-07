#include<iostream>
#include<deque>
using namespace std;

struct stack
{
    deque<int>d;
    void push(int val)
    {
        d.push_front(val);
    }
    void pop()
    {
        if(d.empty())return;
        d.pop_front();
    }
    void display()
    {
        int k=d.size();
        while(k--)
        {
            cout<<d.front()<<" ";
            d.push_back(d.front());
            d.pop_front();
        }
        cout<<endl;
    }
};

struct queue
{
    deque<int> d;
    void push(int val)
    {
        d.push_back(val);
    }
    void pop()
    {
        if(d.empty())return;
        d.pop_front();
    }
    void display()
    {
        int k=d.size();
        while(k--)
        {
            cout<<d.front()<<" ";
            d.push_back(d.front());
            d.pop_front();
        }
        cout<<endl;
    }
};

int main(){
    stack st;
    st.push(5);
    st.display();
    st.push(4);
    st.display();
    st.push(3);
    st.display();
    st.pop();
    st.display();
    cout<<endl;
    queue q;
    q.push(5);
    q.display();
    q.push(4);
    q.display();
    q.push(3);
    q.display();
    q.pop();
    q.display();
    return 0;
}