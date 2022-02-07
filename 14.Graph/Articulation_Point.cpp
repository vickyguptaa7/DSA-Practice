#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int> list[], int src, int parent, int &timer,
         vector<bool> &visit, vector<int> &time, vector<int> &low, vector<bool> &isarticulation)
{
    int children = 0;
    visit[src] = true;
    time[src] = timer;
    low[src] = timer++;
    for (auto x : list[src])
    {
        if (parent == x)
            continue;

        if (visit[x] == false)
        {
            DFS(list, x, src, timer, visit, time, low, isarticulation);
            low[src] = min(low[src], low[x]);
            if (low[x] >= time[src] && parent != -1)
                isarticulation[src] = true;
        }
        else
            low[src] = min(low[src], time[x]);
    }
    if (parent == -1 && children > 1)
    {
        isarticulation[src] = true;
    }
}

void Articulation_Point(vector<int> list[], int v)
{
    vector<int> time(v, -1), low(v, -1);
    vector<bool> visit(v, false), isartic(v, false);
    int timer = 1;
    time[1] = 0;
    for (int i = 0; i < v; i++)
    {
        if (visit[i] == false)
        {
            DFS(list, 1, -1, timer, visit, time, low, isartic);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (isartic[i] == true)
        {
            cout << i << " ";
        }
    }
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
    list[u].push_back(v);
}

void Print_Graph(vector<int> list[], int v)
{
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int v = 9;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 1);
    Add_Adjacent(list, 2, 5);
    Add_Adjacent(list, 5, 6);
    Add_Adjacent(list, 6, 7);
    Add_Adjacent(list, 7, 8);
    Add_Adjacent(list, 8, 6);

    Print_Graph(list, v);
    Articulation_Point(list, v);
    return 0;
}