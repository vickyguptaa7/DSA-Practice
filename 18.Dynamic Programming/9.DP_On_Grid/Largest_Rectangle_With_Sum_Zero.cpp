#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool Largest_Subarray_With_Zero_Sum(vector<int> &arr, int *strt, int *fnsh)
{
    vector<int> presum(arr.size());
    presum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        presum[i] = presum[i - 1] + arr[i];
    }
    unordered_map<int, int> umap;
    bool Check = false;
    for (int i = 0; i < arr.size(); i++)
    {
        if (umap.find(presum[i]) != umap.end())
        {
            if (*fnsh - *strt <= i - umap[presum[i]])
            {
                *strt = umap[presum[i]] + 1;
                *fnsh = i;
            }
            Check = true;
        }
        else
        {
            umap.insert({presum[i], i});
        }
        if (presum[i] == 0 && (*fnsh - *strt) <= i + 1)
        {
            *strt = 0;
            *fnsh = i;
            Check = true;
        }
    }
    return Check;
}

int Largest_Rectangle_With_Zero_Sum_Optimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int final_left = 0, final_right = 0, final_top = 0, final_bottom = 0, max_rectangle = 0;
    int start = 0, finish = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> col_sum(n, 0);
        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                col_sum[k] += matrix[k][j];
            }
            bool isTrue = Largest_Subarray_With_Zero_Sum(col_sum, &start, &finish);
            if (isTrue)
            {
                int rectangle = (j - i + 1) * (finish - start + 1);
                if (rectangle >= max_rectangle)
                {
                    final_left = i;
                    final_right = j;
                    final_top = start;
                    final_bottom = finish;
                    max_rectangle = rectangle;
                }
            }
        }
    }
    cout << "\n\n";
    for (int i = final_top; i <= final_bottom; i++)
    {
        for (int j = final_left; j <= final_right; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int Largest_Rectangle_With_Zero_Sum_Brute(vector<vector<int>> &matrix, int n, int m) // T.C -> O(n^6)
{
    int largest_rectangle = 0;
    int left = 0, right = 0, top = 0, bottom = 0;
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
                    int rectangle = (i2 - i1) * (j2 - j1);
                    if (sum == 0 && largest_rectangle <= rectangle)
                    {
                        largest_rectangle = rectangle;
                        left = i1;
                        right = i2;
                        top = j1;
                        bottom = j2;
                    }
                }
            }
        }
    }
    cout << "\n\n";
    for (int i = left; i <= right; i++)
    {
        for (int j = top; j <= bottom; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << Largest_Rectangle_With_Zero_Sum_Brute(arr, n, m) << "\n";
    cout << Largest_Rectangle_With_Zero_Sum_Optimal(arr) << "\n";
    return 0;
}
/*
3 3
1  2  3
-3 -2 -1
1  7  5

4 4
9  7 16  5
1 -6 -7  3
1  8  7  9
7 -2  0 10

4 2
7 16
-6 -7
8 7
-2 0
*/