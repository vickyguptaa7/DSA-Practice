#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
    TrieNode *get(char ch)
    {
        return child[ch - 'a'];
    }
    void put(char ch, TrieNode *root)
    {
        child[ch - 'a'] = root;
    }
    bool isContainKey(char ch)
    {
        return child[ch - 'a'] != nullptr;
    }
};

int Distinct_Substring_In_String(string str)
{
    TrieNode *root = new TrieNode();
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        TrieNode *curr = root;
        for (int j = i; j < str.length(); j++)
        {
            if (!curr->isContainKey(str[j]))
            {
                result++;
                curr->put(str[j], new TrieNode());
            }
            curr = curr->get(str[j]);
        }
    }
    result++;
    return result;
}

int main()
{
    string str;
    cin >> str;
    cout << Distinct_Substring_In_String(str) << "\n";
    return 0;
}