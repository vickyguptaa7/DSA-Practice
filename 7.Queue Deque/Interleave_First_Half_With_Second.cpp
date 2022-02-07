#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> Interleave(queue<int> q)
{
    queue<int> ans;
    stack<int>st;
    int n=q.size();

    for(int i=0;i<n/2;i++)
    {
        st.push(q.front());
        q.pop();
    }

    for(int i=0;i<n/2;i++)
    {
        q.push(st.top());
        st.pop();
    }

    for(int i=0;i<n/2;i++)
    {
        q.push(q.front());
        q.pop();
    }

    for(int i=0;i<n/2;i++)
    {
        st.push(q.front());
        q.pop();
    }

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            ans.push(st.top());
            st.pop();
        }
        else
        {
            ans.push(q.front());
            q.pop();
        }
    }
    return ans;
}

void Display(queue<int> q, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    Display(q, q.size());

    Display(Interleave(q), q.size());
    return 0;
}