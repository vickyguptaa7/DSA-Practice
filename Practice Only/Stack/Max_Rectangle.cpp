#include <iostream>
#include <stack>
using namespace std;

int Histogram(int arr[], int n)
{
    stack<int> st;
    int ans[n];
    for (int i = 0; i < n; i++)
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
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            ans[i] = n - ans[i] - 1;
        else
            ans[i] = st.top() - ans[i] - 1;
        st.push(i);
    }
    int Max = -1;
    for (int i = 0; i < n; i++)
    {
        Max = max(ans[i] *= arr[i], Max);
    }
    return Max;
}

int Area(int **arr, int n, int m)
{
    int Max = -1, histo[m]={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]!=0)
            histo[j]+=arr[i][j];
            else
            histo[j]=0;
        }
        Max=max(Max,Histogram(histo,m));
    }
    return Max;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    cout << Area(arr, n, m) << endl;
    return 0;
}