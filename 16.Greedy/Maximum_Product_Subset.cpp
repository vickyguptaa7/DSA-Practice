#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Subset_Product(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];
    int neg_count = 0, zero_count = 0, neg_max = -1e9, product = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg_count++;
            neg_max = max(neg_max, arr[i]);
        }
        else if (arr[i] == 0)
        {
            zero_count++;
            continue;
        }
        product *= arr[i];
    }
    if (neg_count % 2 == 1)
    {
        if (zero_count > 0 && neg_count == 1 && neg_count + zero_count == n)
            return 0;
        product /= neg_max;
    }
    return product;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Max_Subset_Product(arr, n) << endl;
    return 0;
}