#include <iostream>
#include <stack>
using namespace std;

void Sort(stack<int> &st, int val)
{
    if (st.empty() || st.top() >= val)
    {
        st.push(val);
        return;
    }
    int data = st.top();
    st.pop();
    Sort(st, val);
    st.push(data);
}

void Sort_Stack(stack<int> &st)
{
    if (st.empty())
        return;
    int val = st.top();
    st.pop();
    Sort_Stack(st);
    Sort(st, val);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.push(num);
    }
    Sort_Stack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}