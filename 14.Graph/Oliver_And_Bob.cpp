#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS_Euler(int src, int &time, vector<int> list[], vector<pair<int, int>> &Time)
{
    Time[src].first = time++;
    for (auto x : list[src])
    {
        if (Time[x].first == 0)
        {
            DFS_Euler(x, time, list, Time);
        }
    }
    Time[src].second = time++;
}

string Oliver_Game(vector<int> list[], int v, int Oliver, int Bob, int Move)
// Move->0 Towards Castle Move->1 Towards Leave
{
    vector<pair<int, int>> Time(v, {0, 0});
    int time = 1;
    DFS_Euler(1, time, list, Time);
    if ((Time[Bob].first > Time[Oliver].first && Time[Bob].second < Time[Oliver].second && Move == 0) || (Time[Bob].first < Time[Oliver].first && Time[Bob].second > Time[Oliver].second && Move == 1)) // Oliver Present In SubTree
    {
        return "YES";
    }
    else
        return "NO";
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
    list[u].push_back(v);
}

void Print_Adjacency_List(vector<int> list[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v = 10;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 3);
    Add_Adjacent(list, 2, 6);
    Add_Adjacent(list, 2, 7);
    Add_Adjacent(list, 6, 9);
    Add_Adjacent(list, 7, 8);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 3, 5);
    Print_Adjacency_List(list, v);
    cout << endl;
    cout<<Oliver_Game(list, v, 2, 8, 0)<<endl;
    cout<<Oliver_Game(list, v, 2, 8, 1)<<endl;
    cout<<Oliver_Game(list, v, 6, 5, 1)<<endl;
    cout<<Oliver_Game(list, v, 6, 5, 0)<<endl;
    cout<<Oliver_Game(list, v, 9, 1, 1)<<endl;
    return 0;
}
/*
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1
*/