#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Longest_Path_With_Hurdles(int x, int y, int fx, int fy, int move, int &longest_path, vector<vector<int>> land)
{
    if (x >= land.size() || y >= land[0].size() || x < 0 || y < 0 || land[x][y] != 1)
        return;
    if (fx == x && fy == y)
    {
        longest_path = max(longest_path, move);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        land[x][y] = 2;
        Longest_Path_With_Hurdles(x + dx[i], y + dy[i], fx, fy, move + 1, longest_path, land);
        land[x][y] = 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    vector<vector<int>> land(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
        }
    }
    int longest_path = 0;
    Longest_Path_With_Hurdles(sx, sy, fx, fy, 0, longest_path, land);
    cout << longest_path << endl;
    return 0;
}
/*
3 10
0 0
1 7
1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1

5 6
2 2
3 3
1 1 0 1 0 1
0 1 1 1 0 1
1 1 1 1 1 1
0 0 1 1 1 1
1 0 1 1 1 1
*/