#include <iostream>
#include <algorithm>

using namespace std;

int check(int **mat, int Mid, int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] <= Mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        count += low;
    }
    return count;
}

int Mat_Median(int **mat, int n, int m,int k)
{
    int Min = mat[0][0];
    int Max = mat[0][m - 1];
    for (int i = 0; i < n; i++)
    {
        Min = min(mat[i][0], Min);
        Max = max(mat[i][m - 1], Max);
    }
    while (Max > Min)
    {
        int mid = Min + (Max - Min) / 2;

        if (check(mat, mid, n, m) >=k)
        {
            Max = mid;
        }
        else
        {
            Min = mid + 1;
        }
    }
    return Min;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    int k;
    cin>>k;
    for (int i = 0; i < n; i++)
    {
        sort(mat[i], mat[i] + m);
    }
    cout << Mat_Median(mat, m, n,k) << endl;
    return 0;
}