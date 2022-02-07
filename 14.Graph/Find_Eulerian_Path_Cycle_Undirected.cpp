#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

void DFS(int src, vector<int> list[], bool isVisited[])
{
    isVisited[src] = true;
    for (auto x : list[src])
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
    for (int i = 0; i < v; i++) // finding first connected componenet
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

int is_Euler_Path_Cycle(vector<int> list[], int v)
{
    if (!Connected_Graph(list, v))
        return 0;
    int odd = 0;
    for (int i = 0; i < v; i++)
    {
        if (list[i].size() & 1)
        {
            odd++;
        }
    }
    if (odd > 2)
        return 0;
    return (odd == 0) ? 1 : 2;
}

void DFS_Euler(int src, vector<unordered_map<int, int>> &list, stack<int> &EulerTour)
{
    while (list[src].size() > 0)
    {
        int newnode = list[src].begin()->first; // To Get First Element Of Map

        // We Know That A-B => A->B and B->A
        // Removing The A->B
        list[src][newnode]--;
        if (list[src].begin()->second == 0)
        {
            list[src].erase(newnode);
        }
        // Removing The B->A
        list[newnode][src]--;
        if (list[newnode][src] == 0)
        {
            list[newnode].erase(src);
        }
        DFS_Euler(newnode, list, EulerTour);
    }
    EulerTour.push(src);
}

void Find_Eluer_Path_Cycle(vector<int> list[], int v)
{
    int Check = is_Euler_Path_Cycle(list, v);
    if (Check == 0)
    {
        cout << "Not Eulerian Graph" << endl;
        return;
    }
    int startnode = -1;
    if (Check == 1) // Eulerian Circuit
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
    else // Eulerian Path
    {
        for (int i = 0; i < v; i++)
        {
            if (list[i].size() & 1)
            {
                startnode = i;
                break;
            }
        }
    }
    vector<unordered_map<int, int>> newlist(v);
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            newlist[i][x]++;
        }
    }
    stack<int> EulerTour;
    DFS_Euler(startnode, newlist, EulerTour);
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
    int v = 12;
    vector<int> list[v];
    // Add_Adjacent(list, 1, 2);
    // Add_Adjacent(list, 2, 1);
    // Add_Adjacent(list, 2, 3);
    // Add_Adjacent(list, 5, 2);
    // Add_Adjacent(list, 4, 5);
    // Add_Adjacent(list, 4, 3);
    // Add_Adjacent(list, 4, 6);
    // Add_Adjacent(list, 4, 6);
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
    Find_Eluer_Path_Cycle(list, v);
    return 0;
}