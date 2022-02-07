#include <iostream>
#include <stack>
using namespace std;

int Celebrity_Brute(bool **arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        bool chk=false;
        for (int i = 0; i < n; i++)
        {
            if (j!= i && (arr[i][j] == 0 || arr[j][i] == 1))
            {
                chk=true;
                break;
            }
        }
        if(!chk)return j;
    }
    return -1;
}

int Celebrity_Stack(bool **arr, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() != 1)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();

        if (arr[i][j] == 1)
            st.push(j);
        else
            st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (st.top() != i && (arr[i][st.top()] == 0 || arr[st.top()][i] == 1))
            return -1;
    }
    return st.top();
}

int Celebrity_Optimal(bool **arr, int n) // Two Pointer
{
    int a = 0, b = n - 1;
    while (b > a)
    {
        if (arr[a][b] == 1)
        {
            a++;
        }
        else
        {
            b--;
        }
    }
    // a or b wiil be our candidates we have to confirm them for celebrity

    for (int i = 0; i < n; i++)
    {
        if (i == a)
            continue;
        if (arr[i][a] == 0 || arr[a][i] == 1)
            return -1;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    bool **arr = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << Celebrity_Brute(arr, n) << endl;
    return 0;
}