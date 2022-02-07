#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS_Hamil(int v, int src, vector<int> list[], bool isVisited[],vector<int>&ans)
{
    isVisited[src]=true;
    ans.push_back(src);
    if (v == ans.size())
    {
        for (auto x : list[src])
        {
            if (ans.front() == x)
            {
                return true;
            }
        }
        return false;
    }
    for(auto x:list[src])
    {
        if(isVisited[x]==false)
        {
            if(DFS_Hamil(v,x,list,isVisited,ans))return true;
        }
    }
    ans.pop_back();
    isVisited[src]=false;
    return false;
}

void Hamiltonian_Cycle(vector<int> list[], int v)
{
    bool isVisited[v] = {0};
    vector<int> ans;
    int count = 0;
    if(DFS_Hamil(6, 1, list, isVisited, ans))
    {
        cout<<"Found"<<endl;
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else 
    {
        cout<<"No Such Cycle"<<endl;
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
    int v = 8;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 5);
    Add_Adjacent(list, 4, 1);
    Add_Adjacent(list, 4, 5);
    Add_Adjacent(list, 3, 6);
    Add_Adjacent(list, 5, 6);
    
    Print_Adjacency_List(list, v);
    cout << endl;
    Hamiltonian_Cycle(list,v);
    return 0;
}