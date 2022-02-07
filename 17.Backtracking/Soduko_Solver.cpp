#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int row, int col, int num, vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++) // square matrix
    {
        if (board[row][i] == num) // col check
            return false;

        if (board[i][col] == num) // col check
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool Sudoku_Solver(vector<vector<int>> &board)
{
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[0].size(); col++)
        {
            if (board[row][col] != 0)
                continue;
            for (int i = 1; i <= board.size(); i++)
            {
                if (isSafe(row, col, i, board))
                {
                    board[row][col] = i;
                    if (Sudoku_Solver(board))
                        return true;
                    board[row][col] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 9;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (Sudoku_Solver(board))
    {
        cout << endl
             << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Not Possible" << endl;
    return 0;
}
/*
9
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/