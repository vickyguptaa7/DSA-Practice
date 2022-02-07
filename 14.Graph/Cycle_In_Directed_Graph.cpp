#include <bits/stdc++.h>
using namespace std;

void Add_Adjacent(vector<int> list[], int v, int u)
{
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

bool DFS_Traversal(vector<int> list[], bool isVisited[], bool recurstack[], int node)
{
    isVisited[node] = true;
    recurstack[node] = true;
    for (int i = 0; i < list[node].size(); i++)
    {
        if (isVisited[list[node][i]] == false)
        {
            if (DFS_Traversal(list, isVisited, recurstack, list[node][i]))
                return true;
        }
        else if (recurstack[list[node][i]] == true)
            return true;
    }
    recurstack[node] = false;
    return false;
}

bool BFS_Detection(vector<int>list[],int v)
{
    int indegree[v]={0};
    for(int i=0;i<v;i++)
    {
        for(auto x:list[i])
        {
            indegree[x]++;
        }
    }
    queue<int>que;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            que.push(i);
        }
    }
    int count=0;
    while(que.size())
    {
        int node=que.front();
        que.pop();
        for(auto x:list[node])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                que.push(x);
            }
        }
        count++;
    }

    return count!=v;
}

bool DFS(vector<int> list[], int v)
{
    bool isVisited[v] = {0};
    bool recurstack[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!isVisited[i])
        {
            if (DFS_Traversal(list, isVisited, recurstack, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v = 4;
    vector<int> list[v];
    Add_Adjacent(list, 0, 1);
    Add_Adjacent(list, 1, 0);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 1);
    Print_Graph(list, 4);
    cout << endl;
    cout << DFS(list, v) << endl;
    cout << BFS_Detection(list, v) << endl;

    return 0;
}