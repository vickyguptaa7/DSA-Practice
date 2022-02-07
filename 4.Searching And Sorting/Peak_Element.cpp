#include <iostream>
using namespace std;

int Peak_Element(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (j >= i)
    {
        int mid = i + (j - i) / 2;
        if (mid > 0 && mid < n-1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid + 1] < arr[mid])
            {
                return mid;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        if (mid == 0)
        {
            if (arr[0] > arr[1])
                return 0;
            else
                return 1;
        }
        else if (mid == n - 1)
        {
            if (arr[mid - 1] < arr[mid])
                return mid;
            else
                return mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Peak_Element(arr, n) << endl;
    return 0;
}