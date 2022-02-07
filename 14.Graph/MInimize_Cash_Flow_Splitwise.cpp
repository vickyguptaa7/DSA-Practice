#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
}

void Print_Graph(vector<pair<int, int>> list[], int v)
{
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
}

void Minimize_Cash_Flow(vector<pair<int, int>> list[], int v)
{
    vector<int> Balance(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            Balance[i] -= x.second;
            Balance[x.first] += x.second;
        }
    }

    // Used Multiset As There Will Be Repeated Values And Set Bcoz We Need To Find Min And Max Value Of Transaction
    multiset<pair<int, int>> Records;
    for (int i = 0; i < v; i++)
    {
        if (Balance[i] != 0)
            Records.insert({Balance[i], i});
    }
    // New Graph To Show Min Cash Flow Transaction
    vector<pair<int, int>> minTransc[v];

    while (!Records.empty())
    {
        int payer = Records.begin()->second, reciever = Records.rbegin()->second;
        int pay_amt = Records.begin()->first, recieve_amt = Records.rbegin()->first;
        Records.erase(Records.begin());
        Records.erase(prev(Records.end()));
        int amount = min(-pay_amt, recieve_amt);
        pay_amt += amount;
        recieve_amt -= amount;
        minTransc[payer].push_back({reciever, amount});
        if (pay_amt)
        {
            Records.insert({pay_amt, payer});
        }
        if (recieve_amt)
        {
            Records.insert({recieve_amt, reciever});
        }
    }
    Print_Graph(minTransc, v);
}

int main()
{
    int v = 5;
    vector<pair<int, int>> list[v];
    // Add_Adjacent(list, 0, 1, 100);
    // Add_Adjacent(list, 0, 2, 50);
    // Add_Adjacent(list, 1, 0, 50);
    // Add_Adjacent(list, 2, 1, 50);

    // Add_Adjacent(list, 0, 3, 4);
    // Add_Adjacent(list, 0, 4, 1);
    // Add_Adjacent(list, 1, 3, 5);
    // Add_Adjacent(list, 1, 4, 2);
    // Add_Adjacent(list, 2, 3, 3);
    // Add_Adjacent(list, 2, 4, 8);

    
    Add_Adjacent(list, 0, 1, 8);
    Add_Adjacent(list, 2, 3, 4);
    Add_Adjacent(list, 2, 4, 6);

    Print_Graph(list, v);
    cout << endl;
    Minimize_Cash_Flow(list, v);
    return 0;
}
/*
0 ->Vicky
1 ->Jugnu
2 ->Bhanu
0 -> (1,100) (2,50)
1 -> (0,50)
2 -> (1,50)

Eg
0 ->A
1 ->B
2 ->C
3 ->D
4 ->E

0 ->(3,4) (4,1)
1 ->(3,5) (4,2)
2 ->(3,3) (4,8)
*/