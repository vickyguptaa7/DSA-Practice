#include <iostream>
#include <math.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class Disjoint_Set
{
    int *parent;
    int *rank;
    int size;

public:
    Disjoint_Set(int capacity)
    {
        size = capacity;
        parent = new int[size];
        rank = new int[size];
        initializer();
    }
    void initializer()
    {
        for (int i = 0; i < size; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int x_rep = Find(x), y_rep = Find(y);
        if (x_rep == y_rep)
            return;
        if (rank[x_rep] > rank[y_rep])
            parent[y_rep] = x_rep;
        else if (rank[x_rep] < rank[y_rep])
            parent[x_rep] = y_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

bool mycomp(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
    return get<2>(t1) < get<2>(t2);
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

void Kruskal_Algorithm(vector<tuple<int, int, int>> Edges, int e, int n)
{
    sort(Edges.begin(), Edges.end(), mycomp);

    vector<pair<int, int>> list[n];


    Disjoint_Set Graph(n);

    for (int i = 0,v_count=0; i < e && v_count < n-1; i++)
    {
        int v1 = get<0>(Edges[i]), v2 = get<1>(Edges[i]), wt = get<2>(Edges[i]);
        if (Graph.Find(v1) == Graph.Find(v2))
            continue;
        Graph.Union(v1, v2);
        list[v1].push_back({v2, wt});
        list[v2].push_back({v1, wt});
        v_count++;
    }

    Print_Graph(list, n);
}

int main()
{
    int e = 5, n = 5;
    vector<tuple<int, int, int>> Edges;
    for (int i = 0; i < e; i++)
    {

        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        Edges.push_back(make_tuple(v1, v2, wt));
    }
    Kruskal_Algorithm(Edges, e, n);
    return 0;
}
/*
0 1 10
0 2 20
2 3 30
3 4 40
1 3 25
*/