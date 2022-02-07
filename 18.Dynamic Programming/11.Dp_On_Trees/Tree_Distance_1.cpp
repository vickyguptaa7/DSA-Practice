#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS_1(int src, vector<int> list[], int depth[])
{
    for (auto curr : list[src])
    {
        DFS_1(curr, list, depth);
        depth[src] = max(depth[src], 1 + depth[curr]);
    }
}

void DFS_2(int src, int parent, vector<int> list[], int depth[])
{
    for (auto curr : list[src])
    {
        DFS_2(curr, src, list, depth);
    }
    if (parent != -1)
        depth[src] = max(depth[src], 1 + depth[parent]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> list[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
    }
    int depth[n + 1] = {0};
    DFS_1(1, list, depth);
    DFS_2(1, -1, list, depth);
    for (auto x : depth)
        cout << x << " ";
    cout << "\n";
    return 0;
}
/*
7
0 1
0 2
1 3
1 4
2 5
2 6
*/