#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
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
    void setEnd()
    {
        isEnd = true;
    }
    bool endWith()
    {
        return isEnd;
    }
    bool isContainKey(char ch)
    {
        return child[ch - 'a'] != nullptr;
    }
    void delEnd()
    {
        isEnd = false;
    }
};

struct Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void Insert(string str)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainKey(str[i]))
            {
                curr->put(str[i], new TrieNode());
            }
            curr = curr->get(str[i]);
        }
        curr->setEnd();
    }
    bool Search(string str)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainKey(str[i]))
            {
                return false;
            }
            curr = curr->get(str[i]);
        }
        return curr->endWith();
    }
    bool Longest_Word_With_All_Prefix(string str)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainKey(str[i]))
            {
                return false;
            }
            curr = curr->get(str[i]);
            if (curr->endWith() == false)
                return false;
        }
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> all_word;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            all_word.push_back(str);
        }
        Trie *root = new Trie();
        for (int i = 0; i < n; i++)
        {
            root->Insert(all_word[i]);
        }
        string result;
        int largest_word = 0;
        for (int i = 0; i < n; i++)
        {
            if (root->Longest_Word_With_All_Prefix(all_word[i]))
            {
                if (largest_word < all_word[i].size())
                {
                    largest_word = all_word[i].size();
                    result = all_word[i];
                }
                else if (largest_word == all_word[i].size() && result.compare(all_word[i]) > 0)
                {
                    largest_word = all_word[i].size();
                    result = all_word[i];
                }
            }
        }
        if (largest_word == 0)
        {
            cout << "None\n";
        }
        else
        {
            cout << result << "\n";
        }
    }
    return 0;
}
/*
2
6
n ni nin ninj ninja ninga
*/