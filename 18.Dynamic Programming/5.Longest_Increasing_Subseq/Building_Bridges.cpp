#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(pair<int, int> b1, pair<int, int> b2)
{
    if (b1.first != b2.first)
        return b1.first < b2.first;
    else
        return b1.second < b2.second;
}

int Max_Bridges(int north[], int south[], int n)
{
    vector<pair<int, int>> Bridge_Pairs;
    for (int i = 0; i < n; i++)
        Bridge_Pairs.push_back(make_pair(north[i], south[i]));
    sort(Bridge_Pairs.begin(), Bridge_Pairs.end(), mycomp);
    vector<int> LIS(n, 1);
    // LIS
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Bridge_Pairs[i].second >= Bridge_Pairs[j].second)
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }
    int Max = 0;
    for (auto x : LIS)
    {
        if (Max < x)
            Max = x;
    }
    return Max;
}

int Max_Bridges_Optemize(int north[], int south[], int n)
{
    vector<pair<int, int>> Bridge_Pairs;
    for (int i = 0; i < n; i++)
        Bridge_Pairs.push_back(make_pair(north[i], south[i]));
    sort(Bridge_Pairs.begin(), Bridge_Pairs.end(), mycomp);

    vector<int> Tail;
    Tail.push_back(Bridge_Pairs[0].second);
    for (int i = 1; i < n; i++)
    {
        if (Tail.back() <= Bridge_Pairs[i].second)
        {
            Tail.push_back(Bridge_Pairs[i].second);
        }
        else
        {
            int indx = upper_bound(Tail.begin(), Tail.end(), Bridge_Pairs[i].second) - Tail.begin();
            Tail[indx] = Bridge_Pairs[i].second;
        }
    }
    return Tail.size();
}

int main()
{
    int n;
    cin >> n;
    int north[n], south[n];
    for (int i = 0; i < n; i++)
    {
        cin >> north[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> south[i];
    }
    cout << Max_Bridges(north, south, n) << "\n";
    cout << Max_Bridges_Optemize(north, south, n) << "\n";
    return 0;
}
/*
8
5 2 3 8 4 7 6 6
3 4 2 7 1 5 9 5


8
3 4 2 7 1 5 9 5
5 2 3 8 4 7 6 6
*/
