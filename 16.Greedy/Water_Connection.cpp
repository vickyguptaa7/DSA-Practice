#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>Topo_Sort(vector<pair<int,int>>list[],int n)
{
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto x:list[i])
        {
            indegree[x.first]++;
        }
    }
    queue<int>que;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            que.push(i);
        }
    }
    vector<int>ans;
    while(!que.empty())
    {
        int src=que.front();
        que.pop();
        ans.push_back(src);
        for(auto node:list[src])
        {
            indegree[node.first]--;
            if(indegree[node.first]==0)
            {
                que.push(node.first);
            }
        }
    }
    return ans;
}

void DFS(int src,vector<pair<int,int>>list[],bool isVisited[],int &min_dia,int &end)
{
    isVisited[src]=1;
    for(auto x:list[src])
    {
        if(isVisited[x.first]==0)
        {
            min_dia=min(min_dia,x.second);
            end=x.first;
            DFS(x.first,list,isVisited,min_dia,end);
        }
    }
}

void Water_Connection(vector<int>a,vector<int>b,vector<int>d,int n,int p)
{
    vector<pair<int,int>>list[n];
    for(int i=0;i<p;i++)
    {
        list[a[i]].push_back({b[i],d[i]});
    }    
    vector<int>Topo=Topo_Sort(list,n);
    bool isVisited[n]={0};
    vector<vector<int>>answer;
    for(auto i:Topo)
    {
        int min_dia=1e9,end=-1;
        if(isVisited[i]==0)
        {
            DFS(i,list,isVisited,min_dia,end);
        }
        if(end!=-1)
        {
            answer.push_back({i,end,min_dia});
        }
    }
    for(int i=0;i<answer.size();i++)
    {
        for(auto x:answer[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,p;
    cin>>n>>p;
    n++;
    vector<int>a(p),b(p),d(p);
    for(int i=0;i<p;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<p;i++)
    {
        cin>>b[i];
    }
    
    for(int i=0;i<p;i++)
    {
        cin>>d[i];
    }
    Water_Connection(a,b,d,n,p);
    return 0;
}

/*

9 6
7 5 4 2 9 3 
4 9 6 8 7 1 
98 72 10 22 17 66

*/