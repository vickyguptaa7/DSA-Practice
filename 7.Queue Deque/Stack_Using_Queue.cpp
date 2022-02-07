#include <iostream>
#include <queue>
using namespace std;

struct stack1 // push In O(n) pop in O(1)
{
    queue<int> q1, q2;
    void push(int val)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        if (q1.size() == 0)
            return;
        q1.pop();
    }
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return q1.size();
    }
    void display()
    {
        if (q1.size() == 0)
            cout << "Empty" << endl;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
            cout << q1.back() << " ";
        }
        cout << endl;
    }
};

struct stack2 // pop in O(n)  push In O(1)
{
    queue<int> q1, q2;
    void pop()
    {
        if (q1.size() == 0)
            return;
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int size()
    {
        return q1.size();
    }
    int top()
    {
        return q1.back();
    }
    void push(int val)
    {
        q1.push(val);
    }
    void display()
    {
        int n = q1.size();
        reverse();
        for (int i = 0; i < n; i++)
        {
            cout << q1.front() << " ";
            q1.push(q1.front());
            q1.pop();
        }
        cout << endl;
        reverse();
    }
    void reverse()
    {
        if(q1.empty())
        {
            return;
        }
        int data=q1.front();
        q1.pop();
        reverse();
        q1.push(data);
    }
};

struct stack3 // using recursion single queue
{
    queue<int> q;
    void push(int val)
    {
        int n = q.size();
        q.push(val);

        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (q.size() == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        q.pop();
    }
    int size()
    {
        return q.size();
    }
    int top()
    {
        if (q.size() == 0)
        {
            cout << "Empty" << endl;
            return -1;
        }
        return q.front();
    }
    void display()
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            cout << q.front() << " ";
            q.push(q.front());
            q.pop();
        }
        cout << endl;
    }
};

int main()
{
    stack2 st;
    st.push(12);
    st.push(5);
    cout << st.top() << endl;
    st.display();
    st.push(4);
    cout << st.top() << endl;
    st.display();

    st.pop();
    st.display();
    cout << st.top() << endl;

    return 0;
}