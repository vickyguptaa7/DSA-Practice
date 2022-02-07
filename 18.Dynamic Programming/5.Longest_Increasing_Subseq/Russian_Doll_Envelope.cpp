#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(pair<int, int> d1, pair<int, int> d2)
{
    if (d1.first != d2.first)
    {
        return d1.first < d2.first;
    }
    else
    {
        return d1.second > d2.second;
    }
}

int Maximum_Envelope_Doll(pair<int, int> Doll[], int n)
{
    sort(Doll, Doll + n, mycomp);
    // LIS
    vector<int> LIS(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Doll[i].second > Doll[j].second)
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }
    int Max = 0;
    for (auto x : LIS)
        if (Max < x)
            Max = x;
    return Max;
}

int Maximum_Envelope_Doll_Optemize(pair<int, int> Doll[], int n)
{
    sort(Doll, Doll + n, mycomp);
    // LIS
    vector<int> Tail;
    Tail.push_back(Doll[0].second);
    for (int i = 1; i < n; i++)
    {
        if (Doll[i].second > Tail.back())
        {
            Tail.push_back(Doll[i].second);
        }
        else
        {
            int indx = upper_bound(Tail.begin(), Tail.end(), Doll[i].second) - Tail.begin();
            if (indx > 0 && Tail[indx - 1] == Doll[i].second)
                continue;
            Tail[indx] = Doll[i].second;
        }
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> Doll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Doll[i].first;
        cin >> Doll[i].second;
    }
    cout << Maximum_Envelope_Doll(Doll, n) << "\n";

    return 0;
}
/*
8
5 3
2 4
3 2
8 7
4 1
7 5
6 9
6 5

8
3 5
4 2
2 3
7 8
1 4
5 7
9 6
5 6


*/