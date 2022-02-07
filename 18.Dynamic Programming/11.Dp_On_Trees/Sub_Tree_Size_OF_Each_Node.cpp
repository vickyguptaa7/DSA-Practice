#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int src, vector<int> list[], int subSize[])
{
    subSize[src] = 1;
    for (auto curr : list[src])
    {
        DFS(curr, list, subSize);
        subSize[src] += subSize[curr];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> list[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
    }
    int subSize[n] = {0};
    DFS(0, list, subSize);
    for (auto x : subSize)
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