#include <bits/stdc++.h>
using namespace std;

bool BFS_Traversal(vector<int> list[], int colour[], int node)
{
    queue<int> que;
    colour[node] = 1;
    que.push(node);
    while (que.size())
    {
        int curr = que.front();
        que.pop();
        for (auto x : list[curr])
        {
            if (colour[x] == 0)
            {
                colour[x] = (colour[curr] == 1) ? 2 : 1;
                que.push(x);
            }
            else if (colour[x] == colour[curr])
            {
                return false;
            }
        }
    }
    return true;
}

bool BFS(vector<int> list[], int v)
{
    int colour[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (colour[i] == 0)
        {
            if (!BFS_Traversal(list, colour, i))
                return false;
        }
    }
    return true;
}

bool DFS_Traversal(vector<int> list[], int colour[], int node)
{
    if (colour[node] == -1)
        colour[node] = 1;

    for (auto x : list[node])
    {
        if (colour[x] == 0)
        {
            colour[x] = (colour[node] == 1) ? 2 : 1;
            if(!DFS_Traversal(list,colour,x))
            return false;
        }
        else if (colour[x] == colour[node])
        {
            return false;
        }
    }
    return true;
}

bool DFS(vector<int> list[], int v)
{
    int colour[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (colour[i] == 0)
        {
            if (!DFS_Traversal(list, colour, i))
                return false;
        }
    }
    return true;
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
    list[u].push_back(v);
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
    int v = 5;
    vector<int> list[v];
    Add_Adjacent(list, 0, 1);
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 4, 1);
    Print_Graph(list, 5);
    cout << endl;
    cout << BFS(list, v) << endl;
    cout << DFS(list, v) << endl;
    return 0;
}