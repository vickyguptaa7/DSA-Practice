#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Odd_Times_Occuring_Number(int n, int arr[])
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = (res ^ arr[i]);
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Odd_Times_Occuring_Number(n, arr) << "\n";
    return 0;
}