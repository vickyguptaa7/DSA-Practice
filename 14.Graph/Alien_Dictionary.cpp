#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

// General Case
string Alien_Dictionary_General(vector<string> wordlist, int n)
{
    unordered_map<char, int> indegree;
    for (auto x : wordlist)
    {
        string str = x;
        for (int i = 0; i < str.length(); i++)
        {
            indegree[str[i]] = 0;
        }
    }
    unordered_map<char, set<char>> list;
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = wordlist[i], word2 = wordlist[i + 1];
        bool check=false;
        /* 
        It Checks Wheter The Two Word Are Same And Length Of First Is 
        Big like abc ab we have to return "" in this case
        */
        int len = min(word1.length(), word2.length());
        for (int j = 0; j < len; j++)
        {
            if (word1[j] != word2[j])
            {
                list[word1[j]].insert(word2[j]);
                indegree[word2[j]]++;
                check=true;
                break;
            }
        }
        if(!check&&word1.length()>word2.length())
        {
            return "";
        }
    }
    queue<char> que;
    for (auto node : indegree)
    {
        if (node.second == 0)
        {
            que.push(node.first);
        }
    }
    int count = 0;
    vector<char> topo;
    while (que.size())
    {
        char node = que.front();
        que.pop();
        count++;
        topo.push_back(node);
        for (auto x : list[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                que.push(x);
            }
        }
    }
    string ans;
    if (count == indegree.size())
    {
        for (auto x : topo)
            ans += x;
        return ans;
    }
    else
        return ans;
}

// K Is For First K English Alphabets
void Alien_Dictionary(vector<string> wordlist, int n, int k)
{
    int indegree[k] = {0};
    vector<int> list[k];
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = wordlist[i], word2 = wordlist[i + 1];
        int len = min(word1.length(), word2.length());
        for (int j = 0; j < len; j++)
        {
            if (word1[j] != word2[j])
            {
                list[word1[j] - 'a'].push_back(word2[j] - 'a');
                indegree[word2[j] - 'a']++;
                break;
            }
        }
    }
    queue<char> que;
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }
    int count = 1;
    vector<char> topo;
    while (que.size())
    {
        int size = que.size();
        while (size--)
        {
            int node = que.front();
            que.pop();
            topo.push_back(node + 'a');
            for (auto x : list[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    que.push(x);
                }
            }
        }
        count++;
    }

    if (count >= k)
    {
        reverse(topo.begin(), topo.end());
        for (auto x : topo)
            cout << x << " ";
    }
    else
    {
        cout << "Not Possible" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> wordlist(n);
    for (int i = 0; i < n; i++)
        cin >> wordlist[i];
    cout << Alien_Dictionary_General(wordlist, n) << endl;
    return 0;
}
/*
baa abcd abca cab cad
*/