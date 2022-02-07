#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Maximum_Arithematic_Slice_Optemize(int arr[], int n)
{
    int Slice[n] = {0}; // Dp Initialize
    int No_Of_Slice = 0;
    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2])
        {
            Slice[i] = Slice[i - 1] + 1;
        }
        No_Of_Slice += Slice[i];
    }
    return No_Of_Slice;
}

int Maximum_Arithematic_Slice(int arr[], int n)
{
    int No_Of_Slice = 0;
    for (int i = 2; i < n; i++)
    {
        for (int j = i; j >= 2; j--)
        {
            if (arr[j] - arr[j - 1] == arr[j - 1] - arr[j - 2])
            {
                No_Of_Slice += 1;
            }
            else
                break;
        }
    }
    return No_Of_Slice;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Maximum_Arithematic_Slice(arr, n) << "\n";
    cout << Maximum_Arithematic_Slice_Optemize(arr, n) << "\n";
    return 0;
}