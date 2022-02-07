#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool Knight_Tour(int x, int y, int move, vector<vector<int>> &board)
{
    if (x < 0 || y < 0 || y >= board.size() || x >= board.size() || board[x][y] != 0)
        return false;
    if (move == board.size() * board.size() - 1)
    {
        board[x][y] = move;
        return true;
    }
    for (int i = 0; i < 8; i++)
    {
        board[x][y] = move;
        if (Knight_Tour(x + dx[i], y + dy[i], move + 1, board))
        {
            return true;
        }
        board[x][y] = 0;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (Knight_Tour(0, 0, 0, board))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
    return 0;
}