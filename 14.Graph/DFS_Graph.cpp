#include <bits/stdc++.h>
using namespace std;

void DFS_Traversal(vector<int> list[], int s, bool isVisited[])
{
    if (isVisited[s] == true)
        return;
    isVisited[s] = true;
    cout << s << " ";
    for (int i = 0; i < list[s].size(); i++)
    {
        DFS_Traversal(list, list[s][i], isVisited);
    }
}

void DFS(vector<int> list[], int v)
{
    bool isVisited[v + 1] = {0};
    for (int i = 0; i < v; i++)
    {
        if (isVisited[i] == false)
        {
            DFS_Traversal(list, 0, isVisited);
        }
    }
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[u].push_back(v);
    list[v].push_back(u);
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
    Add_Adjacent(list, 0, 1);
    Add_Adjacent(list, 0, 2);
    Add_Adjacent(list, 1, 3);
    Add_Adjacent(list, 1, 4);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 4, 5);

    Print_Graph(list, 5);
    cout << endl;
    DFS(list, 6);
    return 0;
}