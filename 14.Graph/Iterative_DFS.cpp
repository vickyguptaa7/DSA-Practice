#include<iostream>
#include<math.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void DFS_Stack(vector<int>list[],int src,int v,bool isVisited[],vector<int>&dfsans)
{
    stack<int>st;
    st.push(src);
    isVisited[src]=true;
    while(st.size())
    {
        int node=st.top();
        st.pop();
        dfsans.push_back(node);
        for(auto x:list[node])
        {
            if(isVisited[x]==false)
            {
                isVisited[x]=true;
                st.push(x);
            }
        }
    }
}

void DFS_Iterative(vector<int>list[],int v)
{
    bool isVisited[v]={0};
    vector<int>dfsans;
    for(int i=0;i<v;i++)
    {
        if(isVisited[i]==false)
        {
            DFS_Stack(list,i,v,isVisited,dfsans);
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<dfsans[i]<<" ";
    }
    cout<<endl;
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
    int v = 6;
    vector<int> list[v];
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 3);
    Add_Adjacent(list, 3, 2);
    Add_Adjacent(list, 3, 4);
    Add_Adjacent(list, 4, 5);
    Add_Adjacent(list, 5, 3);
    Print_Graph(list, v);
    DFS_Iterative(list,v);
    return 0;
}