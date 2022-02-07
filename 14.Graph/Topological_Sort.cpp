#include <bits/stdc++.h>
using namespace std;

void Topological_DFS(vector<int> list[], bool isVisited[], stack<int> &st, int node)
{
    isVisited[node] = true;
    for (auto x : list[node])
    {
        if (isVisited[x] == false)
        {
            Topological_DFS(list, isVisited, st, x);
        }
    }
    st.push(node);
}

vector<int> DFS(vector<int> list[], int v)
{
    bool isVisited[v] = {0};
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (isVisited[i] == false)
        {
            Topological_DFS(list, isVisited, st, i);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> Topological_BFS(vector<int> list[], int v)
{
    vector<int> ans;
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            indegree[x]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        ans.push_back(node);
        for (auto x : list[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                que.push(x);
            }
        }
    }
    return ans;
}

void Print_Array(vector<int> arr)
{
    cout << endl;
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
    // list[u].push_back(v);
}

void Print_Graph(vector<int> list[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
    int v = 6;
    vector<int> list[v];
    // Add_Adjacent(list, 5, 0);
    // Add_Adjacent(list, 5, 2);
    // Add_Adjacent(list, 2, 3);
    // Add_Adjacent(list, 3, 1);
    // Add_Adjacent(list, 4, 1);
    // Add_Adjacent(list, 4, 0);
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 4);
    Add_Adjacent(list, 4, 3);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 2, 5);
    Add_Adjacent(list, 3, 5);
    Print_Graph(list, 6);
    cout << endl;
    Print_Array(DFS(list, v));
    Print_Array(Topological_BFS(list, v));
    return 0;
}