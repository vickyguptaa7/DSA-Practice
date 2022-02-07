#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void DFS(int node, vector<int> list[], bool isVisited[])
{
    isVisited[node] = true;
    for (auto x : list[node])
    {
        if (isVisited[x] == false)
        {
            DFS(x, list, isVisited);
        }
    }
}

int Connected_Graph(vector<int> list[], int v)
{
    int node = -1;
    for (int i = 0; i < v; i++)
    {
        if (list[i].size() > 0)
        {
            node = i;
            break;
        }
    }
    if (node == -1)
        return true;
    bool isVisited[v] = {0};
    DFS(node, list, isVisited);
    for (int i = 0; i < v; i++)
    {
        if (isVisited[i] == false && list[i].size() > 0)
        {
            return false;
        }
    }
    return true;
}

int isEuler_Path_Circuit(vector<int> list[], int v, vector<int> &in, vector<int> &out)
{
    if (!Connected_Graph(list, v))
        return 0;
    for (int i = 0; i < v; i++)
    {
        for (auto node : list[i])
        {
            in[node]++;
            out[i]++;
        }
    }
    int incount = 0, outcount = 0;
    for (int i = 0; i < v; i++)
    {
        if ((in[i] - out[i]) == 1)
            incount++;
        else if ((out[i] - in[i]) == 1)
            outcount++;
        else if (abs(in[i] - out[i]) > 1)
            return 0;
    }
    if (incount == 0 && outcount == 0)
        return 1;
    else if (incount == 1 && outcount == 1)
        return 2;
    else
        return 0;
}

void DFS_Euler(int src, vector<int> list[], vector<int> &out, stack<int> &EulerTour)
{
    while (out[src] != 0)
    {
        out[src]--;
        DFS_Euler(list[src][out[src]], list, out, EulerTour);
    }
    EulerTour.push(src);
}

void Find_Euler_Path_Heirholzer(vector<int> list[], int v)
{
    vector<int> in(v, 0), out(v, 0);
    int Check = isEuler_Path_Circuit(list, v, in, out);
    if (Check == 0)
    {
        cout << "No Such Path Exist!" << endl;
        return;
    }
    int startnode = -1;
    if (Check == 1) // Eulerian Circuit Present In Given Graph
    {
        for (int i = 0; i < v; i++)
        {
            if (list[i].size() > 0)
            {
                startnode = i;
                break;
            }
        }
    }
    else // Eulerain Path Is Present In The Graph Only
    {
        for (int i = 0; i < v; i++)
        {
            if (out[i] - in[i] == 1)
            {
                startnode = i;
                break;
            }
        }
    }
    stack<int> EulerTour;
    DFS_Euler(startnode, list, out, EulerTour);
    if (EulerTour.empty())
    {
        cout << "There Is No Edegs In Graph" << endl;
        return;
    }
    if (Check == 1)
    {
        cout << "Euler Circuit Is Present : \n";
    }
    else
        cout << "Euler Path Is Present Only : \n";
    while (!EulerTour.empty())
    {
        cout << EulerTour.top() << " ";
        EulerTour.pop();
    }
}

void Add_Adjacent(vector<int> list[], int v, int u)
{
    list[v].push_back(u);
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
    int v = 12;
    vector<int> list[v];
    // Add_Adjacent(list, 1, 2);
    // Add_Adjacent(list, 2, 3);
    // Add_Adjacent(list, 3, 4);
    // Add_Adjacent(list, 4, 1);
    // Add_Adjacent(list, 4, 5);
    // Add_Adjacent(list, 3, 6);
    // Add_Adjacent(list, 5, 6);

    // Add_Adjacent(list, 1, 2);
    // Add_Adjacent(list, 2, 3);
    // Add_Adjacent(list, 3, 4);
    // Add_Adjacent(list, 2, 5);
    // Add_Adjacent(list, 5, 2);
    // Add_Adjacent(list, 4, 5);
    // Add_Adjacent(list, 3, 6);
    // Add_Adjacent(list, 5, 6);

    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 3);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 2);
    Add_Adjacent(list, 2, 4);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 4, 5);
    Add_Adjacent(list, 4, 6);
    Add_Adjacent(list, 5, 6);
    Add_Adjacent(list, 5, 7);
    Add_Adjacent(list, 5, 8);
    Add_Adjacent(list, 6, 7);
    Add_Adjacent(list, 6, 8);
    Add_Adjacent(list, 7, 8);
    Add_Adjacent(list, 7, 9);
    Add_Adjacent(list, 8, 9);
    Add_Adjacent(list, 9, 10);
    Add_Adjacent(list, 9, 11);
    Add_Adjacent(list, 11, 10);

    Print_Adjacency_List(list, v);
    cout << endl;
    Find_Euler_Path_Heirholzer(list, v);
    return 0;
}
