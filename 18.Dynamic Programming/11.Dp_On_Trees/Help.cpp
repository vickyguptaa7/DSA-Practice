#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> parant(N);
vector<int> sz(N);

void make_set(int v)
{
    parant[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    if (v == parant[v])
    {
        return v;
    }
    return parant[v] = find_set(parant[v]);
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            parant[a] = b;
            sz[b] += sz[a];
        }
        else
        {
            parant[b] = a;
            sz[a] += sz[b];
        }
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    int cost = 0;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++)
    {

        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            continue;
        }
        else
        {
            cout << u << "--" << v << endl;
            cost = cost + w;
            union_set(u, v);
        }
    }
    cout << cost << endl;
    return 0;
}