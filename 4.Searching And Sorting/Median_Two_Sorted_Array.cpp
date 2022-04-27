#include <iostream>
using namespace std;

float Median(int arr1[], int arr2[], int n, int m)
{
    if (m > n)
    {
        return Median(arr2, arr1, m, n);
    }
    int low = 0, high = n;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = (n + m + 1) / 2 - mid1;
        int min1 = (mid1 != n) ? arr1[mid1] : INT_MAX;
        int max1 = (mid1 != 0) ? arr1[mid1 - 1] : INT_MIN;

        int min2 = (mid2 != m) ? arr2[mid2] : INT_MAX;
        int max2 = (mid2 != 0) ? arr2[mid2 - 1] : INT_MIN;
        cout << low << " " << high << "\n";
        if (min1 >= max2 && min2 >= max1)
        {
            if ((n + m) % 2 == 0)
                return (float(max(max1, max2)) + float(min(min1, min2))) / 2;
            else
                return float(max(max1, max2));
        }
        else if (max1 > min2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }

    cout << Median(a1, a2, n, m) << endl;

    return 0;
}