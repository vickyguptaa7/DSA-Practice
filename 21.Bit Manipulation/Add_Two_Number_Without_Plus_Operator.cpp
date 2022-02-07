#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Add_Number(int a, int b)
{
    while (b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int Subtract_Number(int a, int b)
{
    while (b != 0)
    {
        int carry = (~a) & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << Add_Number(a, b) << "\n";
    cout << Subtract_Number(a, b) << "\n";
    return 0;
}