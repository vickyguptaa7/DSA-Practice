#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Subset_Sum_K(int arr[], int sum, int s, int n, int k, vector<int> ele)
{
    if (s >= n)
    {
        if (sum == k)
        {
            for (auto x : ele)
                cout << x << " ";
            cout << "\n";
        }
        return;
    }

    if (k >= sum + arr[s])
    {
        Subset_Sum_K(arr, sum, s + 1, n, k, ele);
        ele.push_back(arr[s]);
        Subset_Sum_K(arr, sum + arr[s], s + 1, n, k, ele);
    }
    else
    {
        Subset_Sum_K(arr, sum, s + 1, n, k, ele);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> ele;
    Subset_Sum_K(arr, 0, 0, 5, 10, ele);
    return 0;
}