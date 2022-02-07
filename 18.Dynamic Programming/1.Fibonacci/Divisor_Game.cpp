#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool Divisor_Game_Recur(int n)
{
    if (n == 1)
        return 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (Divisor_Game_Recur(n - i) == 0)
                return 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    (Divisor_Game_Recur(n))
        ? cout << "Alice\n"
        : cout << "Bob\n";

    return 0;
}