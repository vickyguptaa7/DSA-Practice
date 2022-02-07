#include <bits/stdc++.h>
using namespace std;

void BFS_Shortest_Path(vector<int> list[], int v, int src)
{
    int Distance[v];
    for (int i = 0; i < v; i++)
        Distance[i] = INT_MAX;
    queue<int> que;
    que.push(src);
    Distance[src] = 0;
    while (que.size())
    {
        int node = que.front();
        que.pop();
        for (auto x : list[node])
        {
            if (Distance[node] + 1 < Distance[x])
            {
                Distance[x] = Distance[node] + 1;
                que.push(x);
            }
        }
    }
    for (int i = 0; i < v; i++)
        cout<<Distance[i]<<" ";
    cout<<endl;
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
    list[u].push_back(v);
}

void Print_Adjacency_List(vector<int> list[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v = 8;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 3, 5);
    Add_Adjacent(list, 4, 6);
    Add_Adjacent(list, 5, 6);
    Add_Adjacent(list, 6, 7);
    Print_Adjacency_List(list, v);
    cout << endl;
    BFS_Shortest_Path(list,v,1);
    return 0;
}