#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Missing_Number(int n, int arr[])
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = (res ^ arr[i]);
    for (int i = 1; i <= n + 1; i++)
    {
        res = (res ^ i);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }
    cout << Missing_Number(n, arr) << "\n";
    return 0;
}