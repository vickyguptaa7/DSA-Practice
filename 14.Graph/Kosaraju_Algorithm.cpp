#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector<int> TopoSort(vector<int> list[], int v)
{
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
    vector<int> ans;
    while (que.size())
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

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return ans;
}

void DFS_Topo(vector<int> list[], int src, bool isVisited[], stack<int> &ans)
{
    isVisited[src] = true;
    for (auto x : list[src])
    {
        if (isVisited[x] == false)
        {
            DFS_Topo(list, x, isVisited, ans);
        }
    }
    ans.push(src);
}

void DFS(vector<int> list[], int src, bool isVisited[])
{
    isVisited[src] = true;
    for (auto x : list[src])
    {
        if (isVisited[x] == false)
        {
            DFS(list, x, isVisited);
        }
    }
    cout<<src<<" ";
}

void Kosaraju_Algorithm(vector<int> list[], int v) // Strongly Connected Component
{
    stack<int> st;
    bool isVisited[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (isVisited[i] == false)
        {
            DFS_Topo(list, i, isVisited, st);
        }
    }

    vector<int> newlist[v];
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            newlist[x].push_back(i);
        }
    }

    for (int i = 0; i < v; i++)
        isVisited[i] = false;

    while (st.size())
    {
        if (isVisited[st.top()] == false)
        {
            DFS(newlist, st.top(), isVisited);
            cout<<endl;
        }
        st.pop();
    }
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
}

void Print_Graph(vector<int> list[], int v)
{
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int v = 6;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 4, 1);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 2, 5);
    Add_Adjacent(list, 3, 5);
    Print_Graph(list, v);
    Kosaraju_Algorithm(list, v);
    return 0;
}