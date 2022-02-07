#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
                count++;
        }
        sort(arr, arr + n, greater<int>());
        for (int i = 0; i < count; i++)
            cout << "1 ";
        if (n - count == 2 && arr[0] == 3 && arr[1] == 2)
        {
            cout << "2 3" << endl;
        }
        else
        {
            for (int i = 0; i < n - count; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}