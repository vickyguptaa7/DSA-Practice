#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

void Prims_Algorithm(vector<pair<int, int>> list[], int v)
{
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({0, {1, -1}}); // {weight,node,parent}
    bool isVisited[v] = {0};
    while (pq.size())
    {
        int node = pq.top().second.first;
        int parentnode = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();
        if (isVisited[node] == true)
            continue;
        isVisited[node] = true;
        if (parentnode != -1)
            cout << parentnode << "\t" << node << "\t" << weight << endl;

        for (auto x : list[node])
        {
            if (isVisited[x.first] == false)
            {
                pq.push({x.second, {x.first, node}});
            }
        }
    }
}

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
    list[u].push_back({v, w});
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
    cout << endl;
}

int main()
{
    int v = 8;
    vector<pair<int, int>> list[v];
    // Add_Adjacent(list, 1, 4, 40);
    // Add_Adjacent(list, 1, 2, 10);
    // Add_Adjacent(list, 2, 3, 10);
    // Add_Adjacent(list, 3, 4, 10);
    // Add_Adjacent(list, 3, 5, 2);
    // Add_Adjacent(list, 5, 6, 3);
    // Add_Adjacent(list, 6, 7, 3);
    // Add_Adjacent(list, 5, 7, 8);
    Add_Adjacent(list,1,2,2);
    Add_Adjacent(list,1,4,1);
    Add_Adjacent(list,4,3,3);
    Add_Adjacent(list,3,2,4);
    Add_Adjacent(list,2,5,5);
    Add_Adjacent(list,3,5,1);
    Print_Graph(list, v);
    Prims_Algorithm(list, v);
    return 0;
}