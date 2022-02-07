#include <iostream>
#include <stack>
using namespace std;

struct queue1 // push in O(n) And Pop In O(1)
{
    stack<int> st1, st2;
    void push(int val)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    void pop()
    {
        if (st1.empty())
        {
            cout << "Empty" << endl;
        }
        st1.pop();
    }
    int size()
    {
        return st1.size();
    }
    void display()
    {
        if (st1.size() == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        while (!st1.empty())
        {
            cout << st1.top() << " ";
            st2.push(st1.top());
            st1.pop();
        }
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        cout << endl;
    }
    int back()
    {
        if (st1.size() != 0)
            return st1.top();
    }
};

struct queue2  // push in O(1) And Pop In O(n)
{
    stack<int>st1,st2;
    void pop()
    {
        if(st1.empty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        while(st1.size()!=1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    void push(int val)
    {
        st1.push(val);
    }
    int size()
    {
        return st1.size();
    }
    int back()
    {
        return st1.top();
    }
    void display()
    {
        if(st1.empty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        while(!st2.empty())
        {
            cout<<st2.top()<<" ";
            st1.push(st2.top());
            st2.pop();
        }
        cout<<endl;
    }
};

struct queue3 // using recursion
{
    stack<int> st;
    void pop()
    {
        if(st.empty())return;

        if(st.size()==1){
            st.pop();
            return;
        }
        int val=st.top();
        st.pop();
        pop();
        st.push(val);
    }
    void push(int val)
    {
        st.push(val);
    }
    int size()
    {
        return st.size();
    }
    void display()
    {
        if(st.empty())
        {
            cout<<"Empty"<<endl;
            return;
        }
    }
    int back()
    {
        if(st.empty())
        {
            cout<<"Empty"<<endl;
        }
        return st.top();
    }
};

int main()
{
    // queue2 q;
    // q.push(1);
    // q.push(2);
    // q.display();
    // q.push(3);
    // q.display();

    // q.pop();
    // q.display();
    // q.pop();
    // q.display();
    // q.push(6);
    // q.display();


    queue3 q;
    q.push(1);
    cout<<q.back()<<endl;
    q.push(2);
    cout<<q.back()<<endl;
    q.push(3);
    cout<<q.back()<<endl;
    
    q.pop();
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.back()<<endl;
    
    return 0;
}