#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct nodes
{
    int u;
    int v;
    int wt;
    nodes(int src, int x, int weight)
    {
        u = src;
        v = x;
        wt = weight;
    }
};

void Bellman_Ford_Algorithm(vector<pair<int, int>> list[], int v)
{
    int inf = 1000000000;
    vector<int> distance(v, inf);
    vector<nodes> edges;
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            nodes n(i, x.first, x.second);
            edges.push_back(n);
        }
    }
    distance[0] = 0;
    for (int i = 1; i <= v - 1; i++)
    {
        for (auto x : edges)
        {
            if (distance[x.u] + x.wt < distance[x.v])
            {
                distance[x.v] = distance[x.u] + x.wt;
            }
        }
    }
    int check = true;
    for (auto x : edges)
    {
        if (distance[x.u] + x.wt < distance[x.v])
        {
            cout << "Negative Weight Cycle" << endl;
            check = false;
            break;
        }
    }
    if (check)
        for (int i=0;i<v;i++)
        {
            cout << distance[i] << " ";
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
    int v = 4;
    vector<pair<int, int>> list[v];
    Add_Adjacent(list, 0, 1, -1);
    Add_Adjacent(list, 2, 0, 4);
    Add_Adjacent(list, 1, 2, -3);
    Add_Adjacent(list, 1, 3, 2);
    Add_Adjacent(list, 2, 3, 3);
    // Add_Adjacent(list, 2, 3, 6);
    // Add_Adjacent(list, 5, 3, 1);
    // Add_Adjacent(list, 6, 1, 8);
    Print_Graph(list, v);
    Bellman_Ford_Algorithm(list, v);
    return 0;
}
