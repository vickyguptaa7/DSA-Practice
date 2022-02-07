#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int Page_Faults_LRU_Map(int pages[], int n, int c) // Using Map T.C -> O(N*C) C For Checking The Min Index While Removing
{
    unordered_map<int, int> umap;
    int pg_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (umap.size() < c)
        {
            if (umap.find(pages[i]) == umap.end())
            {
                pg_faults++;
            }
            umap[pages[i]] = i;
        }
        else
        {
            if (umap.find(pages[i]) != umap.end())
            {
                umap[pages[i]] = i;
            }
            else
            {
                pair<int, int> remove_lru = {umap.begin()->first, umap.begin()->second};
                for (auto x : umap)
                {
                    if (x.second < remove_lru.second)
                    {
                        remove_lru.first = x.first;
                        remove_lru.second = x.second;
                    }
                }
                umap.erase(remove_lru.first);
                umap[pages[i]] = i;
                pg_faults++;
            }
        }
    }
    return pg_faults;
}

int Page_Faults_LRU(int pages[], int n, int c) // Without Map T.C -> O(N*C)
{
    vector<int> pg;
    int pg_faults = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = find(pg.begin(), pg.end(), pages[i]);
        if (it == pg.end())
        {
            if (pg.size() == c)
            {
                pg.erase(pg.begin());
            }
            pg.push_back(pages[i]);
            pg_faults++;
        }
        else
        {
            pg.erase(it);
            pg.push_back(pages[i]);
        }
    }
    return pg_faults;
}

int main()
{
    int n, c;
    cin >> n >> c;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << Page_Faults_LRU(pages, n, c) << endl;
    return 0;
}