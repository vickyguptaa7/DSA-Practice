#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Count_Set_Bit_Naive(int num) // T.C -> O(total no of bits)
{
    int res = 0;
    while (num > 0)
    {
        if ((num & 1) == 1)
            res++;
        num = (num >> 1);
    }
    return res;
}

int Count_Set_Bit_Kerningham(int num) // T.C -> O(total No of set bits)
{
    int res = 0;
    while (num > 0)
    {
        num = (num & (num - 1));
        res++;
    }
    return res;
}

void Initialize(int table[]) // preprocessing for lookup table
{
    table[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        table[i] = (i & 1) + table[i / 2];
    }
}

int Count_Set_Bit_Lookup(int num, int table[]) // T.C -> O(1)
{
    // 0xff -> 8bit largest Number 255
    int res = table[num & 0xff];
    num = (num >> 8);
    res += table[num & 0xff];
    num = (num >> 8);
    res += table[num & 0xff];
    num = (num >> 8);
    res += table[num & 0xff];
    return res;
}

int main()
{
    int n;
    cin >> n;
    int table[256] = {0};
    cout << Count_Set_Bit_Naive(n) << "\n";
    cout << Count_Set_Bit_Kerningham(n) << "\n";
    Initialize(table);
    cout << Count_Set_Bit_Lookup(n, table) << "\n";

    return 0;
}