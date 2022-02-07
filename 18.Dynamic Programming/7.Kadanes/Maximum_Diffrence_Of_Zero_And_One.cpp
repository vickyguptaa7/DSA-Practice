#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Difference_Zero_And_One(string str, int n)
{
    int max_sum = -1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            sum += -1;
        else
            sum += 1;
        if (sum > max_sum)
            max_sum = sum;
        if (sum < 0)
            sum = 0;
    }
    return max_sum;
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    cout << Max_Difference_Zero_And_One(str, n) << "\n";
    return 0;
}