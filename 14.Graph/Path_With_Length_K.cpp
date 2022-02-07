#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS(int src, int parent, vector<pair<int, int>> list[], int k, bool isVisited[],vector<int>&path)
{
    if (k <= 0)
        return true;
    isVisited[src] = 1;
    for (auto node : list[src])
    {
        if (isVisited[node.first] == 0)
            if (DFS(node.first, src, list, k - node.second, isVisited,path))
            {
                path.push_back(node.first);
                if(parent==-1)path.push_back(src);
                return true;
            }
                
    }
    isVisited[src] = 0;
    return false;
}

string Path_Length_More_Than_K(vector<pair<int, int>> list[], int v, int k)
{
    bool isVisited[v] = {0};
    vector<int>path;
    for (int i = 0; i < v; i++)
    {
        if (isVisited[i] == 0)
        {
            if (DFS(i, -1, list, k, isVisited,path))
            {
                for(auto x:path)cout<<x<<" ";
                cout<<endl;
                return "true";
            }
                
        }
    }
    return "false";
}

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
    list[u].push_back({v, w});
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

int main()
{
    int v = 9;
    vector<pair<int, int>> list[v];
    Add_Adjacent(list, 0, 1, 2);
    Add_Adjacent(list, 0, 4, 1);
    Add_Adjacent(list, 1, 2, 3);
    Add_Adjacent(list, 4, 2, 2);
    Add_Adjacent(list, 4, 5, 4);
    Add_Adjacent(list, 2, 3, 6);
    Add_Adjacent(list, 5, 3, 1);
    Add_Adjacent(list, 6, 1, 8);
    Print_Graph(list, v);
    cout<<Path_Length_More_Than_K(list,v,15)<<endl;
    return 0;
}