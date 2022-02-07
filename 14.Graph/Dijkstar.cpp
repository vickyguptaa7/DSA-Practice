#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
void Dijkstras_Algo(vector<pair<int, int>> list[], int v, int src)
{
    int Distance[v];
    for (int i=0;i<v;i++)
        Distance[i] = INT_MAX;
    Distance[src] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(0,src));

    while (pq.size())
    {
        int node = pq.top().second;
        int wsf=pq.top().first;
        pq.pop();
        for (auto x : list[node])
        {
            if (Distance[x.first] > wsf + x.second)
            {
                Distance[x.first] = wsf + x.second;
                pq.push(make_pair(Distance[x.first],x.first));
            }
        }
    }
    for (auto x : Distance)
        cout << x << " ";
    cout << endl;
}

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
    list[u].push_back({v, w});
}

void Print_Graph(vector<pair<int, int>> list[], int v)
{
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int v = 8;
    vector<pair<int, int>> list[v];
    Add_Adjacent(list, 1, 4, 40);
    Add_Adjacent(list, 1, 2, 10);
    Add_Adjacent(list, 2, 3, 10);
    Add_Adjacent(list, 3, 4, 10);
    Add_Adjacent(list, 3, 5, 2);
    Add_Adjacent(list, 5, 6, 3);
    Add_Adjacent(list, 6, 7, 3);
    Add_Adjacent(list, 5, 7, 8);
    // Add_Adjacent(list,1,2,2);
    // Add_Adjacent(list,1,4,1);
    // Add_Adjacent(list,4,3,3);
    // Add_Adjacent(list,3,2,4);
    // Add_Adjacent(list,2,5,5);
    // Add_Adjacent(list,3,5,1);
    
    Print_Graph(list, v);
    Dijkstras_Algo(list, v, 1);
    return 0;
}