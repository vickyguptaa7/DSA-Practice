#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Two_Odd_Appearing_Number(int n, int arr[])
{
    int Xor = 0, res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        Xor = (Xor ^ arr[i]);
    }
    int right_most_set_bit = (Xor & (~(Xor - 1)));
    for (int i = 0; i < n; i++)
    {
        if ((right_most_set_bit & arr[i]) != 0)
            res1 = (res1 ^ arr[i]);
        else
            res2 = (res2 ^ arr[i]);
    }
    cout << res1 << " " << res2 << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
        cin >> x;
    Two_Odd_Appearing_Number(n, arr);
    return 0;
}