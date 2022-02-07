#include <iostream>
using namespace std;

void Min_Flips_Same(bool arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            if (arr[i] != arr[0])
            {
                cout << "From " << i << " To ";
            }
            else
            {
                cout << i - 1 << endl;
            }
        }
    }
    if (arr[n - 1] != arr[0])
    {
        cout << n - 1 << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    bool arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Min_Flips_Same(arr, n);

    return 0;
}