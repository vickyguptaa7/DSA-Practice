#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string No_Two_Adjacent_Same(string str)
{
    unordered_map<char, int> umap;
    for (auto x : str)
        umap[x]++;
    priority_queue<pair<int, char>> pq;
    for (auto x : umap)
        pq.push({x.second, x.first});
    string nstr;
    while (pq.size() > 1)
    {
        pair<int, char> p1 = {pq.top().first - 1, pq.top().second};
        pq.pop();
        pair<int, char> p2 = {pq.top().first - 1, pq.top().second};
        pq.pop();
        nstr += p2.second;
        nstr += p1.second;
        if (p1.first > 0)
            pq.push(p1);
        if (p2.first > 0)
            pq.push(p2);
    }
    if(pq.size()==1)
    {
        if(pq.top().first>1)
        return "";
        else 
        nstr+=pq.top().second;
        pq.pop();
    }

    return nstr;
}

int main()
{
    string str;
    cin >> str;
    cout << No_Two_Adjacent_Same(str) << endl;
    return 0;
}