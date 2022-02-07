#include <iostream>
using namespace std;

int Longest_Subarray(int arr[], int n, int k)
{
    int maxlen = 0, sum = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        while (sum < k)
        {
            sum += arr[j];
            j++;
        }

        while (sum > k)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == k)
        {
            maxlen = max(maxlen, j - i);
            sum += arr[j];
            j++;
        }
    }
    return maxlen;
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
    int k;
    cin >> k;

    cout << Longest_Subarray(arr, n, k) << endl;
    return 0;
}