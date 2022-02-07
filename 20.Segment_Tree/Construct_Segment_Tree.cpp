#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int constructST(int as, int ae, int sti, int arr[], int segTree[])
{
    if (as == ae)
    {
        segTree[sti] = arr[as];
        return arr[as];
    }
    int mid = (as + ae) / 2;
    segTree[sti] = constructST(as, mid, 2 * sti + 1, arr, segTree) + constructST(mid + 1, ae, 2 * sti + 2, arr, segTree);
    return segTree[sti];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int segTree[4 * n] = {0};
    constructST(0, n - 1, 0, arr, segTree);
    for (auto x : segTree)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}