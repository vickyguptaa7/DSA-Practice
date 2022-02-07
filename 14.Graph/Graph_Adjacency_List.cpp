#include<bits/stdc++.h>
using namespace std;

void Add_Adjacent(vector<int>list[],int u,int v) //Unidirected Graph
{
    list[u].push_back(v);
    list[v].push_back(u);
}

void Print_Graph(vector<int>list[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<"-> ";
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
    Add_Adjacent(list,0,2);
    Add_Adjacent(list,1,3);
    Add_Adjacent(list,1,2);

    Print_Graph(list,v);
    return 0;
}