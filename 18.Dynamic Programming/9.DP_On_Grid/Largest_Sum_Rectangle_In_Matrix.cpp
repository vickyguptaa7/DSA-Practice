#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Kadanes_algo(vector<int> &arr, int *strt, int *finish)
{
    int n = arr.size();
    int max_sum = -1e9;
    int sum = 0;
    int l_strt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max_sum)
        {
            max_sum = sum;
            *strt = l_strt;
            *finish = i;
        }
        if (sum < 0)
        {
            sum = 0;
            l_strt = i + 1;
        }
    }
    return max_sum;
}

int Largest_Sum_Rectangle_In_Matrix_Optimal(vector<vector<int>> &matrix, int n, int m)
{
    int max_sum = -1e9;
    int final_left = 0, final_right = 0, final_top = 0, final_bottom = 0;
    int strt = 0, finish = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> row_sum(n, 0);
        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                row_sum[k] += matrix[k][j];
            }
            int sum = Kadanes_algo(row_sum, &strt, &finish);
            if (max_sum < sum)
            {
                max_sum = sum;
                final_left = i;
                final_right = j;
                final_top = strt;
                final_bottom = finish;
            }
        }
    }
    for (int i = final_top; i <= final_bottom; i++)
    {
        for (int j = final_left; j <= final_right; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return max_sum;
}

int Largest_Sum_Rectangle_In_Matrix_Brute(vector<vector<int>> &matrix, int n, int m) // T.C -> O(n^6)
{
    int max_sum = -1e9;
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int i2 = i1; i2 < n; i2++)
            {
                for (int j2 = j1; j2 < m; j2++)
                {
                    int sum = 0;
                    for (int p = i1; p <= i2; p++)
                    {
                        for (int q = j1; q <= j2; q++)
                        {
                            sum += matrix[p][q];
                        }
                    }
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    return max_sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    cout << Largest_Sum_Rectangle_In_Matrix_Brute(matrix, n, m) << "\n";
    cout << Largest_Sum_Rectangle_In_Matrix_Optimal(matrix, n, m) << "\n";
    return 0;
}
/*
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/