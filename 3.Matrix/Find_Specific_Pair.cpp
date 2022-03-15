#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int Specific_Pair_Opt(int **arr, int n, int m)
{
    vector<vector<int>> newArr(n, vector<int>(m, 0));

    newArr[n - 1][m - 1] = arr[n - 1][m - 1];

    int maxv = arr[n - 1][m - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        maxv = max(arr[i][m - 1], maxv);
        newArr[i][m - 1] = maxv;
    }

    maxv = arr[n - 1][m - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        maxv = max(arr[n - 1][i], maxv);
        newArr[n - 1][i] = maxv;
    }

    int maxValue = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            maxValue = max(maxValue, newArr[i + 1][j + 1] - arr[i][j]);
            newArr[i][j] = max(arr[i][j], max(newArr[i][j + 1], newArr[i + 1][j]));
        }
    }
    return maxValue;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "\n\n";
    cout << Specific_Pair_Opt(arr, n, m) << "\n";
    return 0;
}
/*
5 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 6 1 3
-4 -1 1 7 -6
0 -4 10 -5 1
*/