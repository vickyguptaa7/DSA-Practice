#include <bits/stdc++.h>
using namespace std;

void Find_Paht_DFS(vector<int> list[], bool isVisited[], int src, int des, string pth)
{
    if (src == des)
    {
        for (auto x : pth)
        {
            cout << x << "->";
        }
        cout <<des<<" Reached" << endl;
        return;
    }
    isVisited[src] = true;
    for (auto x : list[src])
    {
        if (isVisited[x] == false)
        {
            Find_Paht_DFS(list, isVisited, x, des, pth + to_string(src));
        }
    }
    isVisited[src] = false;
}

void DFS(vector<int> list[], int v, int des)
{
    bool isVisited[v] = {0};
    Find_Paht_DFS(list, isVisited, 1, des, "");
}

bool isPresent_Already(vector<int>arr,int x)
{
    for(auto z:arr)
    {
        if(z==x)return false;
    }
    return true;
}

void Find_Path_BFS(vector<int> list[], int v, int src, int des)
{
    queue<vector<int>> que;
    vector<int> path;
    path.push_back(src);
    que.push(path);
    while (que.size())
    {
        path = que.front();
        que.pop();
        if (path.back() == des)
        {
            for (auto x : path)
                cout << x << "->";
            cout << "Reached" << endl;
        }
        for (auto x : list[path.back()])
        {
            if (isPresent_Already(path, x))
            {
                path.push_back(x);
                que.push(path);
                path.pop_back();
            }
        }
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
    int v = 8;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 3, 5);
    Add_Adjacent(list, 4, 6);
    Add_Adjacent(list, 5, 6);
    Add_Adjacent(list, 6, 7);
    Print_Adjacency_List(list, v);
    cout << endl;
    DFS(list, v, 7);
    cout<<endl;
    Find_Path_BFS(list,v,1,7);
    return 0;
}