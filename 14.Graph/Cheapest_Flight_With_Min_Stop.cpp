#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> ppi;
typedef pair<int, int> pi;
// Dijkstra's Approach
int Cheapest_Flight_With_K_Stops_Dijk(vector<vector<int>> flights, int n, int src, int dst, int k)
{
    vector<pair<int, int>> list[n];

    for (int i = 0; i < flights.size(); i++)
    {
        list[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({0, {src, 0}});

    vector<int> stop(n, 1e9);

    while (pq.size())
    {
        int node = pq.top().second.first;
        int weight = pq.top().first;
        int radial_dist = pq.top().second.second;
        pq.pop();
        if (radial_dist > stop[node] || radial_dist > k + 1)
        {
            continue;
        }
        stop[node] = radial_dist;
        if (dst == node)
        {
            return weight;
        }
        for (auto x : list[node])
        {
            pq.push({weight + x.second, {x.first, radial_dist + 1}});
        }
    }
    return -1;
}

// Bellman Ford
int Cheapest_Flight_With_K_Stops(vector<vector<int>> flights, int n, int src, int dst, int k)
{
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    for (int i = 0; i <= k; i++)
    {
        vector<int>temp;
        temp=distance;
        for(auto edge:flights)
        {
            temp[edge[1]]=min(temp[edge[1]],distance[edge[0]]+edge[2]);
        }
        distance=temp;
    }
    return (distance[dst] == 1e9) ? -1 : distance[dst];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> flight(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> flight[i][0] >> flight[i][1] >> flight[i][2];
    }
    cout << Cheapest_Flight_With_K_Stops(flight, n, 0, 3,0);
    return 0;
}
/*
4
[[0,1,100],[1,2,100],[0,2,500],[2,3,100]]
0
2
2
-->
4
0 1 100
1 2 100
0 2 500
2 3 100
*/