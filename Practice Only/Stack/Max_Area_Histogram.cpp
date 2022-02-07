#include <iostream>
#include <stack>
using namespace std;

int Area(int arr[], int n)
{
    stack<int> st;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
            ans[i] = -1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(i);
            ans[i] = n-ans[i]-1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = n-ans[i]-1;
            else
                ans[i] = st.top()-ans[i]-1;
            st.push(i);
        }
    }
    int Max=-1;
    for(int i=0;i<n;i++)
    {
        Max=max(ans[i]*=arr[i],Max);
    }
    return Max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Area(arr, n) << endl;
    return 0;
}