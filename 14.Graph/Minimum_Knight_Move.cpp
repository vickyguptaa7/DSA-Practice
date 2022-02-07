#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// void Min_Move(int move, int &minmove, )
// {
//     if (x1 <= 0 || y1 <= 0 || x1 > n || y1 > n || isVisit[x1 - 1][y1 - 1] == 1)
//         return;
//     if (x1 == x2 && y1 == y2)
//     {
//         minmove = min(move, minmove);
//         return;
//     }
//     isVisit[x1 - 1][y1 - 1] = 1;
//     Min_Move(move + 1, minmove, x2, y2, n, isVisit);
//                                 -2 +1
//     Min_Move(move + 1, minmove, x1 - 1, y1 + 2, x2, y2, n, isVisit);

//     Min_Move(move + 1, minmove, x1 + 1, y1 + 2, x2, y2, n, isVisit);

//     Min_Move(move + 1, minmove, x1 + 2, y1 + 1, x2, y2, n, isVisit);

//     Min_Move(move + 1, minmove, x1 + 2, y1 - 1, x2, y2, n, isVisit);

//     Min_Move(move + 1, minmove, x1 + 1, y1 - 2, x2, y2, n, isVisit);

//     Min_Move(move + 1, minmove, x1 - 1, y1 - 2, x2, y2, n, isVisit);

//     Min_Move(move + 1, minmove, x1 - 2, y1 - 1, x2, y2, n, isVisit);
//     isVisit[x1 - 1][y1 - 1] = 0;
// }

int BFS_Night_Moves(int x1, int y1, int x2, int y2, int n)
{
    vector<vector<int>> isVisit(n, vector<int>(n, 0));
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    queue<pair<int, int>> que;
    que.push({x1, x2});
    int count = 0;
    while (que.size())
    {
        int size = que.size();
        while (size--)
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            if (x2 == x && y2 == y)
            {
                return count;
            }
            for (int i = 0; i < 8; i++)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < n && isVisit[newx][newy] != true)
                {
                    isVisit[newx][newy] = true;
                    que.push({newx, newy});
                }
            }
        }
        count++;
    }
    return -1;
}

int main()
{
    int n, minmove = INT_MAX;
    cin >> n;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << BFS_Night_Moves(x1, y1, x2, y2, n) << endl;
    return 0;
}