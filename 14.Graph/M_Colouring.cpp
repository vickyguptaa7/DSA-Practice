#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool BFS_Approach(int n, int m, vector<vector<int>> graph)
{
    vector<int> list[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                list[i].push_back(j);
            }
        }
    }
    vector<int> colour(n, 1);
    vector<bool> isVisited(n, 0);
    int colour_cnt = 1;
    for (int i = 0; i < n; i++)
    {

        if (isVisited[i] == true)
            continue;
        queue<int> que;
        isVisited[i] = true;
        que.push(i);
        while (que.size())
        {
            int node = que.front();
            que.pop();

            for (auto src : list[node])
            {
                if (colour[src] ==colour[node])
                    colour[src] += 1;

                colour_cnt = max(colour_cnt, max(colour[node], colour[src]));
                if (colour_cnt > m)
                    return false;

                if (isVisited[src] == false)
                {
                    isVisited[src] = 1;
                    que.push(src);
                }
            }
        }
    }
    return true;
}

bool isSafe(int src, int n, int m, int colour[], vector<vector<int>> graph)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[src][i] && colour[i] == colour[src])
        {
            return false;
        }
    }
    return true;
}

bool solve(int src, int n, int m, int colour[], vector<vector<int>> graph)
{
    if (src == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        colour[src] = i;
        if (isSafe(src, n, m, colour, graph))
        {
            if (solve(src + 1, n, m, colour, graph))
                return true;
        }
        colour[src] = 0;
    }
    return false;
}

bool M_Colouring(vector<vector<int>> graph, int n, int m)
{
    int colour[n] = {0};
    bool check = solve(0, n, m, colour, graph);
    for (auto x : colour)
        if (x != 0)
            cout << x << " ";
    cout << endl;
    return check;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << BFS_Approach(n, m, graph) << endl;
    return 0;
}
/*
14
5
35
7 10 13 14 7 9 8 9 8 13 11 12 6 8 6 9 4 5 4 6 9 14 3 13 11 13 9 10 3 11 8 14 12 13 4 9 3 7 11 14 5 14 4 14 6 11 3 12 12 14 9 13 2 4 9 11 2 5 10 14 2 7 10 11 8 11 10 12 6 13
*/