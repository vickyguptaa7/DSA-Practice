#include <bits/stdc++.h>
using namespace std;
/*
Multisolver
-> Kth Largest
-> Smallest
-> Longest
-> Ciel
-> Floor
*/
class Multisolver
{
public:
    string LargestPath_weight;
    int largestpath = INT_MIN;
    string SmallestPath_weight;
    int smallestPaht = INT_MAX;
    string Floor_Path;
    int Floor_weight = INT_MIN;
    string Ceil_Path;
    int Ceil_weight = INT_MAX;
    string KthLargestPath_weight;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    void Find_Path_DFS(vector<pair<int, int>> list[], bool isVisited[], int src, int des, string path, int weight, int floor, int ceil, int kth)
    {
        if (src == des)
        {
            path+=to_string(des);
            if (largestpath < weight)
            {
                largestpath = weight;
                LargestPath_weight = path + " @" + to_string(weight);
            }
            if (smallestPaht > weight)
            {
                smallestPaht = weight;
                SmallestPath_weight = path + " @" + to_string(weight);
            }
            if (weight < floor)
            {
                Floor_weight = max(Floor_weight, weight);
                Floor_Path = path + " @" + to_string(weight);
            }
            if (weight > ceil&&weight<Ceil_weight)
            {
                Ceil_weight = weight;
                Ceil_Path = path + " @" + to_string(weight);
            }
            if (pq.size() < kth)
            {
                pq.push({weight, path});
            }
            else
            {
                if (pq.top().first < weight)
                {
                    pq.pop();
                    pq.push({weight, path});
                }
            }

            return;
        }
        isVisited[src] = true;
        for (auto x : list[src])
        {
            if (isVisited[x.first] == false)
            {
                Find_Path_DFS(list, isVisited, x.first, des, path + to_string(src), weight + x.second, floor, ceil, kth);
            }
        }
        isVisited[src] = false;
    }

    void DFS(vector<pair<int, int>> list[], int v, int src, int des)
    {
        bool isVisited[v] = {0};
        Find_Path_DFS(list, isVisited, src, des, "", 0, 40, 40, 3);
    }

    void Print_Multisolver()
    {
        cout << "Smallest Weight Path -> " << SmallestPath_weight << endl;
        cout << "Largest Weight Path -> " << LargestPath_weight << endl;
        cout << "Floor Weight Path -> " << Floor_Path << endl;
        cout << "Ceil Weight Path -> " << Ceil_Path << endl;
        cout << "Kth Largest Path -> " << pq.top().second <<" @"<<pq.top().first <<endl;
    }
};

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
    list[u].push_back({v, w});
}

void Print_Graph(vector<pair<int, int>> list[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
}
int main()
{
    int v=7;
    vector<pair<int,int>>list[v];
    Add_Adjacent(list,0,1,10);
    Add_Adjacent(list,1,2,10);
    Add_Adjacent(list,2,3,10);
    Add_Adjacent(list,0,3,40);
    Add_Adjacent(list,3,4,2);
    Add_Adjacent(list,4,5,3);
    Add_Adjacent(list,5,6,3);
    Add_Adjacent(list,4,6,8);
    
    Multisolver object;
    object.DFS(list,v,0,6);
    object.Print_Multisolver();
    
    return 0;
}