#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Partial_Fact(int n, int k)
{
    if (n == 0 || n == 1)
        return 1;
    n--;
    int fact = 1;
    for (int i = 1; i <= n && k >= fact; i++)
        fact *= i;
    return fact;
}

string Kth_Permutation_large(int n, int k)
{
    vector<int> number;
    int fact = Partial_Fact(n, k);
    for (int i = 1; i < n; i++)
    {
        number.push_back(i);
    }
    number.push_back(n);
    k -= 1;
    string ans = "";
    while (true)
    {
        ans += to_string(number[k / fact]);
        number.erase(number.begin() + k / fact);
        if (number.size() == 0)
            break;
        k = k % fact;
        fact = Partial_Fact(number.size(),k);
    }
    return ans;
}

string Kth_Permutation(int n, int k)
{
    vector<int> number;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        number.push_back(i);
        fact *= i;
    }
    number.push_back(n);
    k -= 1;
    string ans = "";
    while (true)
    {
        ans += to_string(number[k / fact]);
        number.erase(number.begin() + k / fact);
        if (number.size() == 0)
            break;
        k = k % fact;
        fact = fact / number.size();
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << Kth_Permutation_large(n, k) << endl;
    return 0;
}