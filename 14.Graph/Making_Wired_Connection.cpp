#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void DFS_Connection(int src,int parent,int &extra,vector<int>list[],bool isVisit[])
{
    isVisit[src]=true;
    for(auto x:list[src])
    {
        if(isVisit[x]==false)
        {
            DFS_Connection(x,src,extra,list,isVisit);
        }
        else if(parent!=x&&parent!=-1)
        {
            extra++;
        }
    }
}

int Wired_Connection(vector<int>list[],int v)
{
    int cp=0,extra=0;
    bool isVisit[v]={false};
    for(int i=0;i<v;i++)
    {
        if(isVisit[i]==0)
        {
            cp++;
            DFS_Connection(i,-1,extra,list,isVisit);
        }
    }
    return (extra>=--cp)?cp:-1;
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

int main(){
   int v = 6;
    vector<int> list[v];
    Add_Adjacent(list, 0, 1);
    Add_Adjacent(list, 0, 2);
    Add_Adjacent(list, 0, 3);
    Add_Adjacent(list, 1, 2);
    Add_Adjacent(list, 1, 3);
    // Add_Adjacent(list, 5, 3);
    Print_Graph(list, v);
    cout<<Wired_Connection(list,v)<<endl;
    return 0;
}