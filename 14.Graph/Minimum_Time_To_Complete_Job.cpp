#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void Topo_Sort_Min_Time(int v,vector<int>list[])
{
    int indegree[v]={0};
    for(int i=0;i<v;i++)
    {
        for(auto x:list[i])
        {
            indegree[x]++;
        }
    }
    queue<int>que;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            que.push(i);
        }
    }
    vector<pair<int,int>>time;
    int count_time=1;
    while(que.size())
    {
        int size=que.size();
        while(size--)
        {
            int node=que.front();
            que.pop();
            time.push_back({node,count_time});
            for(auto x:list[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    que.push(x);
                }
            }
        }
        count_time++;
    }
    sort(time.begin(),time.end());
    for(auto x:time)cout<<x.second<<" ";
    cout<<endl;
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

int main(){
   int v = 10;
    vector<int> list[v];
    Add_Adjacent(list, 0, 2);
    Add_Adjacent(list, 0, 3);
    Add_Adjacent(list, 0, 4);
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 8);
    Add_Adjacent(list, 2, 5);
    Add_Adjacent(list, 5, 6);
    Add_Adjacent(list, 6, 7);
    Add_Adjacent(list, 7, 9);
    Add_Adjacent(list, 3, 5);
    Add_Adjacent(list, 3, 7);
    Add_Adjacent(list, 4, 7);
    Add_Adjacent(list, 1, 2);
    Print_Graph(list, v);
    Topo_Sort_Min_Time(v,list);
    return 0;
}