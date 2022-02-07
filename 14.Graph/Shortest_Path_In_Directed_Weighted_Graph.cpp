#include <bits/stdc++.h>
using namespace std;

vector<int> TopoSort(vector<pair<int, int>> list[], int v, int src)
{
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            indegree[x.first]++;
        }
    }

    queue<int> que;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }
    while (que.size())
    {
        int node = que.front();
        que.pop();
        ans.push_back(node);
        for (auto x : list[node])
        {
            indegree[x.first]--;
            if (indegree[x.first] == 0)
            {
                que.push(x.first);
            }
        }
    }

    return ans;
}

void Shortest_Path_BFS(vector<pair<int, int>> list[], int v, int src)
{
    vector<int> ans = TopoSort(list, v, src);
    int Distance[v] = {0};
    for (int i = 0; i < v; i++)
        Distance[i] = INT_MAX;
    Distance[src] = 0;
    int i = 0;
    while (ans.size() > i)
    {
        int node = ans[i++];
        if(Distance[node]!=INT_MAX)
        {
            for (auto x : list[node])
            {
                if (Distance[x.first] > Distance[node] + x.second)
                {
                    Distance[x.first] = Distance[node] + x.second;
                }
            }
        }
    }

    for (auto x : Distance)
    {
        cout << x << " ";
    }
}

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
}

void Print_Graph(vector<pair<int, int>> list[], int v)
{
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    int v = 9;
    vector<pair<int, int>> list[v];
    Add_Adjacent(list, 0, 1, 2);
    Add_Adjacent(list, 0, 4, 1);
    Add_Adjacent(list, 1, 2, 3);
    Add_Adjacent(list, 4, 2, 2);
    Add_Adjacent(list, 4, 5, 4);
    Add_Adjacent(list, 2, 3, 6);
    Add_Adjacent(list, 5, 3, 1);
    Add_Adjacent(list, 6, 1, 8);
    Print_Graph(list, v);
    Shortest_Path_BFS(list, v, 0);
    return 0;
}