#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int Scrambled_String_Recur(string x, string y)
{
    if (x.compare(y) == 0)
        return true;
    if (x.length() <= 1)
        return false;
    int n = x.length();
    bool flag = false;
    for (int k = 1; k < n; k++)
    {
        if (Scrambled_String_Recur(x.substr(0, k), y.substr(0, k)) && Scrambled_String_Recur(x.substr(k, n - k), y.substr(k, n - k)))
        {
            flag = true;
            break;
        }
        if (Scrambled_String_Recur(x.substr(0, k), y.substr(n - k, k)) && Scrambled_String_Recur(x.substr(k, n - k), y.substr(0, n - k)))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int Scrambled_String_Memo(string x, string y, unordered_map<string, bool> &map)
{
    if (x.compare(y) == 0)
        return true;
    if (x.length() <= 1)
        return false;

    string key = x + " " + y;
    if (map.find(key) != map.end())
        return map[key];

    int n = x.length();
    bool flag = false;
    for (int k = 1; k < n; k++)
    {
        if (Scrambled_String_Memo(x.substr(0, k), y.substr(0, k), map) && Scrambled_String_Memo(x.substr(k, n - k), y.substr(k, n - k), map))
        {
            flag = true;
            break;
        }
        if (Scrambled_String_Memo(x.substr(0, k), y.substr(n - k, k), map) && Scrambled_String_Memo(x.substr(k, n - k), y.substr(0, n - k), map))
        {
            flag = true;
            break;
        }
    }
    map[key] = flag;
    return flag;
}

int main()
{
    string x, y;
    cin >> x >> y;
    unordered_map<string, bool> map;
    cout << Scrambled_String_Recur(x, y) << "\n";
    cout << Scrambled_String_Memo(x, y, map) << "\n";
    return 0;
}