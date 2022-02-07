#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void printBoard(vector<vector<bool>> &board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            if (board[i][j] == false)
            {
                cout << "X ";
            }
            else
            {
                cout << "P ";
            }
        }
        cout << endl;
    }
    cout << "\n\n";
}

int kx[4] = {-1, -2, -2, -1};
int ky[4] = {2, 1, -1, -2};

// bool isSafeknight(int x, int y, vector<vector<int>> &board)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         int newx = x + kx[i], newy = y + ky[i];
//         if (newx >= board.size() || newy >= board.size() || newx < 0 || newy < 0)
//             continue;
//         if (board[newx][newy] == 1)
//             return false;
//     }
//     return true;
// }

// void Knight_Place(int x, int y, int night, vector<vector<int>> &board)
// {
//     if (night == 0)
//     {
//         printBoard(board);
//         return;
//     }
//     for (int i = x; i < board.size(); i++)
//     {
//         for (int j = y; j < board.size(); j++)
//         {
//             if (isSafeknight(i, j, board))
//             {
//                 board[i][j] = 1;
//                 Knight_Place(i, j + 1, night - 1, board);
//                 board[i][j] = 0;
//             }
//         }
//         y = 0;
//     }
// }

bool isSafeForKnight(vector<vector<bool>> &board, int row, int column)
{
    int x[] = {-2, -2, -1, -1};
    int y[] = {-1, 1, 2, -2};
    for (int i = 0; i < 4; ++i)
    {
        if (row + x[i] < 0 || column + y[i] < 0)
        {
            continue;
        }
        if (board[row + x[i]][column + y[i] == 1])
        {
            return false;
        }
    }
    return true;
}

void placeKnights(vector<vector<bool>> &board, int knights, int row = 0, int column = 0)
{
    if (knights == 0)
    {
        printBoard(board);
        cout << endl
             << endl;
        return;
    }
    for (int i = row; i < board.size(); ++i)
    {
        for (int j = column; j < board[0].size(); ++j)
        {
            if (isSafeForKnight(board, i, j))
            {
                board[i][j] = true;
                placeKnights(board, knights - 1, i, j + 1);
                board[i][j] = false;
            }
        }
        column = 0;
    }
}
int main()
{
    int n = 2;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    placeKnights(board, n, 0, 0);
    return 0;
}