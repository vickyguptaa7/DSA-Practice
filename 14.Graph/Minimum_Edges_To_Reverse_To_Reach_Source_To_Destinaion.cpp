#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

int Dijkstra_Algo(int src, int dest, vector<pair<int, int>> list[], int v)
{

    vector<int> distance(v, 1e9);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({ 0,src});
    distance[src] = 0;
    while (pq.size())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if (node == dest)
        {
            return wt;
        }
        for (auto it : list[node])
        {
            if (distance[it.first] > distance[node] + it.second)
            {
                distance[it.first] = distance[node] + it.second;
                pq.push({distance[it.first],it.first});
            }
        }
    }
    return -1;
}

void Model_Graph(vector<pair<int, int>> edges, int n, vector<pair<int, int>> list[])
{
    for (int i = 0; i < n; i++)
    {
        list[edges[i].first].push_back({edges[i].second, 0});
        list[edges[i].second].push_back({edges[i].first, 1});
    }
}

int Minimum_Edges_To_Reverse(int src, int dest, vector<pair<int, int>> edges, int n, int v)
{
    vector<pair<int, int>> list[v];
    Model_Graph(edges, n, list);
    return Dijkstra_Algo(src, dest, list, v);
}

int main()
{
    int n, v;
    cin >> v >> n;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++)
    {
        int frm, to;
        cin >> frm >> to;
        edges.push_back({frm, to});
    }
    cout<<Minimum_Edges_To_Reverse(0,5,edges,n,v);
    return 0;
}
/*

Eg
7
7
0 1
2 1
2 3
5 1
4 5
6 4
6 3

O/P -> 2


*/