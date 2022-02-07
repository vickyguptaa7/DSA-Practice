#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool Bipartite(vector<int>list[],int v)
{
    int colour[v]={0};
    queue<int>que;
    que.push(0);
    colour[0]=1;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(auto x:list[node])
        {
            if(colour[x]==0)
            {
                colour[x]=(colour[node]==1)?2:1;
                que.push(x);
            }
            else if(colour[node]==colour[x])
            {
                return false;
            }
        }
    }
    return true;
}

bool Two_Clique(vector<int>list[],int v)
{
    vector<int>Complment_Graph[v];
    for(int i=0;i<v;i++)
    {
        bool visit[v]={false};
        visit[i]=true;
        for(auto x:list[i])
        {
            visit[x]=true;
        }
        for(int j=0;j<v;j++)
        {
            if(visit[j]==false)
            Complment_Graph[i].push_back(j);
        }
    }
    return Bipartite(Complment_Graph,v);
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
    int v = 5;
    vector<int> list[v];
    Add_Adjacent(list, 0, 1);
    Add_Adjacent(list, 1, 2);
    // Add_Adjacent(list, 0, 2);
    Add_Adjacent(list, 3, 2);
    Add_Adjacent(list, 3, 0);
    // Add_Adjacent(list, 3, 1);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 2, 4);
    
    Print_Adjacency_List(list, v);
    cout << endl;
    cout<<Two_Clique(list, v)<<endl;
    return 0;
}