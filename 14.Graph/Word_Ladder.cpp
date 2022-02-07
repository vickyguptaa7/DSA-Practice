#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string.h>
using namespace std;

void Next_Word(string node, queue<string> &que, unordered_map<string, bool> vmap)
{
    for (int i = 0; i < node.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char ch = j + 97;
            string newnode = node.substr(0, i) + ch + node.substr(i + 1);
            if (node[i] != ch && vmap.find(newnode) != vmap.end() && vmap[newnode] != 1)
            {
                vmap[newnode] = {1};
                que.push(newnode);
            }
        }
    }
}

int Word_Ladder(string swrd, string ewrd, vector<string> wordlist, int n)
{
    unordered_map<string, bool> vmap;
    for (int i = 0; i < n; i++)
    {
        vmap[wordlist[i]] = 0;
    }
    queue<string> que;
    que.push(swrd);
    vmap[swrd] = true;
    int count = 1;
    while (que.size())
    {
        int size = que.size();
        while (size--)
        {
            string node = que.front();
            que.pop();
            if (node == ewrd)
            {
                return count;
            }
            Next_Word(node,que,vmap);
        }
        count++;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    string swrd, ewrd;
    cin >> swrd >> ewrd;
    fflush(stdin);
    vector<string> wordlist(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordlist[i];
    }
    cout << Word_Ladder(swrd, ewrd, wordlist, n);
    return 0;
}
/*
6
hit cog
hot dog dot lot log cog

7
toon plea
poon plee same poie plea plie poin

4
abcv ebad
abcd ebad ebcd xyza
*/