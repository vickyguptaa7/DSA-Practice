#include <bits/stdc++.h>
using namespace std;

bool DFS_Traversal(vector<int> list[], bool isVisited[], int s, int parent)
{

    isVisited[s] = true;
    for (int i = 0; i < list[s].size(); i++)
    {
        if (!isVisited[list[s][i]])
        {
            if (DFS_Traversal(list, isVisited, list[s][i], s))
            {
                return true;
            }
        }
        else if (list[s][i] != parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> list[], int v)
{
    bool isVisited[v + 1] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!isVisited[i])
        {
            if (DFS_Traversal(list, isVisited, i, -1))
                return true;
        }
    }
    return false;
}

bool BFS_Traversal(vector<int> list[], bool isVisited[], int s)
{
    queue<pair<int,int>> que;
    que.push({s,-1});
    isVisited[s] = true;
    while (!que.empty())
    {
        int node = que.front().first;
        int parent=que.front().second;
        que.pop();
        for (auto x:list[node])
        {
            if (!isVisited[x])
            {
                isVisited[x]=true;
                que.push({x,node});
            }
            else if(parent!=x)
            {
                return true;
            }
        }
    }
    return false;
}

bool BFS(vector<int> list[], int v)
{
    bool isVisited[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!isVisited[i])
        {
            if (BFS_Traversal(list, isVisited, i))
                return true;
        }
    }
    return false;
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

int main()
{
    int v = 6;
    vector<int> list[v];
    Add_Adjacent(list, 0, 1);
    Add_Adjacent(list, 1, 2);
    // Add_Adjacent(list, 1, 3);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 2, 4);
    Add_Adjacent(list, 4, 5);

    cout << DFS(list, v) << endl;
    cout<<BFS(list,v)<<endl;
    return 0;
}