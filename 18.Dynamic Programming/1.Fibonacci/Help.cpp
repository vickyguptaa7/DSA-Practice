#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int row = mat.size(), col = mat[0].size();
    vector<int> temp(row * col);
    int p = 0;
    if (r >= row && c >= col)
    {
        return mat;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[p] = mat[i][j];
            p++;
        }
    }
    p = 0;
    vector<vector<int>> res(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[i][j] = temp[p];
            p++;
        }
    }
    return res;
}

void Print(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n = 2;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    Print(matrixReshape(mat, 1, 4));
    return 0;
}