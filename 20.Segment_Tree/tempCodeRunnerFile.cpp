#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int constructSegTree(int si, int ei, int sti, int arr[], int segTree[])
{
    if (si == ei)
    {
        segTree[sti] = arr[si];
        return arr[si];
    }
    int mid = (si + ei) / 2;
    segTree[sti] = constructSegTree(si, mid, 2 * sti + 1, arr, segTree) +
                   constructSegTree(mid + 1, ei, 2 * sti + 2, arr, segTree);
    return segTree[sti];
}

int getSum(int qs, int qe, int si, int ei, int sti, int segTree[])
{
    if (ei < qs || qe < si)
        return 0;
    if (si >= qs && ei <= qe)
        return segTree[sti];
    int mid = (si + ei) / 2;
    return getSum(qs, qe, si, mid, 2 * sti + 1, segTree) + getSum(qs, qe, mid + 1, ei, 2 * sti + 2, segTree);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int segTree[4 * n] = {0};
    constructSegTree(0, n - 1, 0, arr, segTree);
    cout << getSum(0, 2, 0, n - 1, 0, segTree) << "\n";
    cout << "\n";
    return 0;
}