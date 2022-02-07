#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Cherry_Pickup_Recur(int x, int y, vector<vector<int>> &garden)
{
    if (x >= garden.size() || y >= garden[0].size() || garden[x][y] == -1)
    {
        return -1e9;
    }
    if (x == garden.size() - 1 && garden[0].size() - 1)
    {
        return garden[x][y];
    }
    int cherry = garden[x][y];
    cherry += max(Cherry_Pickup_Recur(x + 1, y, garden), Cherry_Pickup_Recur(x, y + 1, garden));
    return cherry;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> garden(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> garden[i][j];
        }
    }
    cout << Cherry_Pickup_Recur(0, 0, garden) << "\n";
    return 0;
}