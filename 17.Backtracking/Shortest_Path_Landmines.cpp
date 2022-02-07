#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Find_Short_Path_DFS(int row, int col, int len, int &min_length, vector<vector<int>> &land)
{
    if (row >= land.size() || col >= land[0].size() ||
        row < 0 || col < 0 || land[row][col] != 1)
        return;

    if (col == land[0].size() - 1)
    {
        if (min_length > len)
        {
            min_length = len;
        }

        return;
    }
    for (int i = 0; i < 4; i++)
    {
        land[row][col] = 2;
        Find_Short_Path_DFS(row + dx[i], col + dy[i], len + 1, min_length, land);
        land[row][col] = 1;
    }
}

vector<vector<int>> Landmine_Impact(vector<vector<int>> &land)
{
    vector<vector<int>> newland(land.size(), vector<int>(land[0].size(), 1));
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            if (land[i][j] == 0)
            {
                newland[i][j] = 0;
                for (int k = 0; k < 4; k++) // marking the impact of the landmine on adjacent cell as we cant go there also
                {
                    if (i + dx[k] >= land.size() || j + dy[k] >= land[0].size() ||
                        i + dx[k] < 0 || j + dy[k] < 0)
                        continue;
                    newland[i + dx[k]][j + dy[k]] = 0;
                }
            }
        }
    }
    return newland;
}

int Find_DFS(vector<vector<int>> land)
{
    int min_length = 1e9;
    vector<vector<int>> newland = Landmine_Impact(land);
    for (int i = 0; i < land.size(); i++)
    {
        if (newland[i][0] != 0)
            Find_Short_Path_DFS(i, 0, 0, min_length, newland);
    }
    return min_length;
}

int Find_Short_Path_BFS(vector<vector<int>> land)
{
    land = Landmine_Impact(land);
    queue<pair<int, int>> que;
    for (int i = 0; i < land.size(); i++)
    {
        if (land[i][0] != 0)
        {
            que.push({i, 0});
            land[i][0]=2;
        }
    }
    int min_distance = -1;
    bool find=false;
    while (!que.empty()&&!find)
    {
        int size = que.size();
        while (size--)
        {
            int x = que.front().first, y = que.front().second;
            if (y == land[0].size() - 1)
            {
                find=true;
                break;
            }
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] >= land.size() || y + dy[i] >= land[0].size() ||
                    x + dx[i] < 0 || y + dy[i] < 0 || land[x + dx[i]][y + dy[i]] != 1)
                    continue;
                land[x + dx[i]][y + dy[i]] = 2;
                que.push({x + dx[i], y + dy[i]});
            }
        }
        min_distance++;
    }
    if (find)
    {
        return min_distance;
    }
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> land(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
        }
    }
    cout << Find_Short_Path_BFS(land) << endl;
    return 0;
}
/*
12 10
1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1

5 5
0 1 1 1 1
1 1 1 0 1
1 1 1 1 1
1 1 1 1 1
0 0 1 1 1
*/