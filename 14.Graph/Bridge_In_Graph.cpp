#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS_Bridge(int src, int parent, int &timer, vector<int> list[], vector<bool> &visit,
                vector<int> &disc, vector<int> &low, vector<string> &Bridge)
{
    visit[src]=true;
    disc[src]=timer;
    low[src]=timer++;
    for(auto x:list[src])
    {
        if(x==parent)continue;
        if(visit[x]==false)
        {
            DFS_Bridge(x,src,timer,list,visit,disc,low,Bridge);
            low[src]=min(low[src],low[x]);
            if(low[x]>disc[src])
            {
                Bridge.push_back(to_string(src)+"-"+to_string(x));
            }
        }
        else low[src]=min(low[src],disc[x]);
    }
}

void Bridge_In_Graph(vector<int> list[], int v)
{
    vector<int> disc(v, -1), low(v, -1);
    vector<bool> visit(v, 0);
    vector<string> Bridge;
    int timer = 1;
    for (int i = 0; i < v; i++)
    {
        if (visit[i] == false)
        {
            DFS_Bridge(1, -1, timer, list, visit, disc, low, Bridge);
        }
    }
    for(int i=0;i<Bridge.size();i++)
    {
        cout<<Bridge[i]<<endl;
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
    int v = 10;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 2, 3);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 4, 5);
    Add_Adjacent(list, 5, 6);
    Add_Adjacent(list, 6, 7);
    Add_Adjacent(list, 7, 8);
    Add_Adjacent(list, 8, 9);

    Print_Graph(list, v);
    Bridge_In_Graph(list,v);
    return 0;
}