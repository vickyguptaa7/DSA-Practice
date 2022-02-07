#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void DFS_Tarjan_SCC(int src, int parent, int &timer, vector<int> list[],
                    vector<bool> &recurvisit, vector<int> &disc, vector<int> &low, stack<int> &st)
{
    recurvisit[src] = true;
    st.push(src);
    disc[src] = low[src] = timer++;
    for (auto x : list[src])
    {
        if (disc[x] == -1)
        {
            DFS_Tarjan_SCC(x, src, timer, list, recurvisit, disc, low, st);
            low[src] = min(low[src], low[x]);
        }
        else if (recurvisit[x])
            low[src] = min(low[src], disc[x]);
    }
    if (disc[src] == low[src])
    {
        while (st.size() && disc[st.top()] != low[st.top()])
        {
            cout << st.top() << " ";
            recurvisit[st.top()] = false;
            st.pop();
        }
        cout << st.top() << endl;
        recurvisit[st.top()] = false;
        st.pop();
    }
}

void Tarjan_Algorihtm(vector<int> list[], int v)
{
    vector<int> disc(v, -1), low(v, -1);
    stack<int> stack;
    vector<bool> recurvisit(v, 0);
    int timer = 1;
    for (int i = 0; i < v; i++)
    {
        if (disc[i] == -1)
        {
            DFS_Tarjan_SCC(i, -1, timer, list, recurvisit, disc, low, stack);
        }
    }
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
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
    int v = 6;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 3);
    Add_Adjacent(list, 3, 2);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 4, 5);
    Add_Adjacent(list, 5, 3);
    Print_Graph(list, v);
    Tarjan_Algorihtm(list, v);
    return 0;
}