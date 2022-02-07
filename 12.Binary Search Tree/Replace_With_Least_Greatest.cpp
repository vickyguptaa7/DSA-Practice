#include <iostream>
using namespace std;

void Replace_With_Least_Greatest_Brute(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int ans = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
                ans = min(ans, arr[j]);
        }
        if (ans == INT_MAX)
            arr[i] = -1;
        else
            arr[i] = ans;
    }
}

void Replace_With_Least_Greatest_Brute(int *arr,int n)
{
    
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Replace_With_Least_Greatest_Brute(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}