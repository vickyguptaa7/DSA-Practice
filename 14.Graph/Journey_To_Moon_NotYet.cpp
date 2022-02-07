#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int Find(int x, vector<int> &parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    parent[x] = Find(parent[x], parent);
    return parent[x];
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_rep = Find(x, parent), y_rep = Find(y, parent);
    if (x_rep == y_rep)
        return;
    if (rank[x_rep] > rank[y_rep])
        parent[y_rep] = x_rep;
    else if (rank[x_rep] < rank[y_rep])
        parent[x_rep] = y_rep;
    else
    {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

long long Valid_Pairs_DSU(vector<pair<int, int>> Pair, int n, int k) // Using DSU
{
    vector<int> parent(n, 0), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < k; i++)
    {
        Union(Pair[i].first, Pair[i].second, parent, rank);
    }
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        Find(i, parent); // To Make Every Element Directly Points To Sets Repersentative
        freq[parent[i]]++;
    }
    vector<long long> Cnt_arr;
    for (auto x : freq)
    {
        Cnt_arr.push_back(x.second);
    }
    long long valid_pairs = 0, presum = 0;
    for (int i = 1; i < Cnt_arr.size(); i++)
    {
        presum += Cnt_arr[i - 1];
        valid_pairs += Cnt_arr[i] * presum;
    }

    return valid_pairs;
}

void DFS(int src, int &count, vector<int> list[], vector<bool>&isVisited)
{
    isVisited[src] = true;
    count++;
    for (auto x : list[src])
    {
        if (isVisited[x] == false)
        {
            DFS(x, count, list, isVisited);
        }
    }
}

int Valid_Pairs_DFS(vector<pair<int, int>> Pair, int n, int k)
{
    vector<int> list[n];
    for (auto x : Pair)
    {
        list[x.first].push_back(x.second);
        list[x.second].push_back(x.first);
    }
    vector<bool> isVisited(n, 0);
    vector<int> freq;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (isVisited[i] == false)
        {
            DFS(i, count, list, isVisited);
        }
        freq.push_back(count);
    }
    long long valid_pairs = 0, presum = 0;
    for (int i = 1; i < freq.size(); i++)
    {
        presum += freq[i - 1];
        valid_pairs += freq[i] * presum;
    }
    return valid_pairs;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> Pair;
    for (int i = 0; i < k; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        Pair.push_back({n1, n2});
    }
    cout << Valid_Pairs_DFS(Pair, n, k) << endl;
    return 0;
}