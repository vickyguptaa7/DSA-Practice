#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Find_Largest_Sum_Subarray_Opt(int arr[], int n)
{
    int max_sum = arr[0], sum = 0, strt = 0, end = 0, newstrt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max_sum < sum)
        {
            max_sum = sum;
            strt = newstrt;
            end = i;
        }
        if (sum < 0)
        {
            newstrt = i + 1;
            sum = 0;
        }
    }
    for (int i = strt; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Find_Largest_Sum_Subarray_Opt(arr, n);
    return 0;
}