#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Copy_Set_Bit_In_Range(int x, int y, int l, int r)
{
    int total = r - l + 1;
    int bitmask = (1 << total);
    bitmask -= 1;
    bitmask = (bitmask << (l - 1));
    bitmask = (bitmask & y);
    x = (bitmask | x);
    return x;
}

int main()
{
    int x, y;
    cin >> x >> y;
    int l, r;
    cin >> l >> r;
    cout << Copy_Set_Bit_In_Range(x, y, l, r) << "\n";
    return 0;
}