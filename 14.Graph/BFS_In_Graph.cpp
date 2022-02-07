#include<bits/stdc++.h>
using namespace std;

void BFS_Traversal(vector<int>list[],int v,int s,bool isVisited[])
{
    queue<int>que;
    que.push(s);
    isVisited[s]=1;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        cout<<node<<" ";
        for(auto x:list[node])
        {
            if(isVisited[x]==false)
            {
                isVisited[x]=true;
                que.push(x);
            }
        }
    }
    cout<<endl;
}

void BFS_Disconected(vector<int>list[],int v)
{
    bool isVisited[v+1]={0};
    for(int i=0;i<v;i++)
    {
        if(isVisited[i]==false)
        {
            BFS_Traversal(list,v,i,isVisited);
        }
    }
}

void Add_Adjacent(vector<int>list[],int v,int u)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

void Print_Graph(vector<int>list[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<" -> ";
        for(auto x:list[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    int v=4;
    vector<int>list[v];
    Add_Adjacent(list,0,1);
    Add_Adjacent(list,1,2);
    Add_Adjacent(list,2,3);
    Add_Adjacent(list,3,1);
    
    Print_Graph(list,4);
    cout<<endl;
    cout<<Add_Adjacent(list,v);
    return 0;
}