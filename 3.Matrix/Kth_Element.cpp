#include <iostream>
#include <algorithm>

using namespace std;

int Kth_Element_Brute(int **arr, int n, int m, int k)
{
    int narr[m * n];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            narr[c] = arr[i][j];
            c++;
        }
    }
    sort(narr, narr + m * n);
    return narr[k-1];
}

int Binary_Search(int **arr, int i, int n, int k)
{
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[i][mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ++ans;
}

int Kth_ELement_Optimal(int **arr, int n, int m, int k)
{
    int Min = INT_MAX, Max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        Min = min(Min, arr[i][0]);
        Max = max(Max, arr[i][m - 1]);
    }

    int low = Min, high = Max;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += Binary_Search(arr, i, m, mid);
        }
        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
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
    int k;
    cin >> k;
    cout << Kth_ELement_Optimal(arr, n, m, k) << endl;
    return 0;
}