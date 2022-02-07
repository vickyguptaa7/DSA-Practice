#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Find_Path(int x, int y, string path, vector<vector<int>> maze, vector<string> &list)
{
    if (x == maze.size() || y == maze[0].size() || y < 0 || x < 0 || maze[x][y] != 1)
        return;
    if (x == maze.size() - 1 && y == maze[0].size() - 1)
    {
        list.push_back(path);
        return;
    }
    maze[x][y] = 2; // marked visited;
    Find_Path(x + 1, y, path + 'D', maze, list);
    Find_Path(x, y + 1, path + 'R', maze, list);
    Find_Path(x - 1, y, path + 'U', maze, list);
    Find_Path(x, y - 1, path + 'L', maze, list);
    maze[x][y] = 1; // mark unvisited;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    vector<string> list;
    Find_Path(0, 0, "", maze, list);
    for(int i=0;i<list.size();i++)
    {
        cout<<list[i]<<endl;
    }
    return 0;
}
/*
4 4
1 0 0 0
1 1 0 1 
1 1 0 0
0 1 1 1
*/