#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int x, int y, vector<vector<int>> mat, vector<vector<int>>&isVisit)
{
    if (x < 0 || y < 0 || x >=mat.size() || y >=mat[0].size() || isVisit[x][y] == 1 || mat[x][y] == 0)
        return;
    isVisit[x][y] = 1;
    DFS(x + 1, y, mat, isVisit);
    DFS(x, y + 1, mat, isVisit);
    DFS(x - 1, y, mat, isVisit);
    DFS(x, y - 1, mat, isVisit);
    DFS(x + 1, y + 1, mat, isVisit);
    DFS(x - 1, y - 1, mat, isVisit);
    DFS(x + 1, y - 1, mat, isVisit);
    DFS(x - 1, y + 1, mat, isVisit);
}

int No_Of_Island(int n, int m, vector<vector<int>> mat)
{
    vector<vector<int>> isVisit(n, vector<int>(m, 0));
    int island = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isVisit[i][j] == 0&&mat[i][j]==1)
            {
                island++;
                DFS(i, j, mat, isVisit);
            }
        }
    }
    return island;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << No_Of_Island(n, m, mat) << endl;
    return 0;
}