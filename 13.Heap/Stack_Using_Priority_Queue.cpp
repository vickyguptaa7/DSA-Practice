#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    priority_queue<pair<int, int>> pq;
    int count;
    public:
    Stack()
    {
        count = 0;
    }
    void push(int val)
    {
        pq.push({count, val});
        count++;
    }
    int pop()
    {
        if (count == 0)
        {
            cout << "Underflow!" << endl;
            return -1;
        }
        int num = pq.top().second;
        pq.pop();
        count--;
        return num;
    }
    int top()
    {
        if (count == 0)
        {
            cout << "Underflow!" << endl;
            return -1;
        }
        return pq.top().second;
    }
    bool isEmpty()
    {
        return count==0;
    }
};

int
main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    while(!st.isEmpty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}