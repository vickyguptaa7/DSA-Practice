#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    int cnt_end_With;
    int cntPrefix;
    TrieNode()
    {
        cnt_end_With = 0;
        cntPrefix = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
    bool isEmpty()
    {
        for (int i = 0; i < 26; i++)
        {
            if (child[i] != nullptr)
                return false;
        }
        return true;
    }
    TrieNode *get(char ch)
    {
        return child[ch - 'a'];
    }
    bool isContainKey(char ch)
    {
        return (child[ch - 'a'] != nullptr);
    }
    void put(char ch, TrieNode *root)
    {
        child[ch - 'a'] = root;
    }
    void increaseEnd()
    {
        cnt_end_With++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cnt_end_With--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cnt_end_With;
    }
    int getPrefix()
    {
        return cntPrefix;
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
            curr->increasePrefix();
        }
        curr->increaseEnd();
    }
    int Search(string str)
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
        return curr->getEnd();
    }
    int Count_Prefix(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!curr->isContainKey(prefix[i]))
                return false;
            curr = curr->get(prefix[i]);
        }
        return curr->getPrefix();
    }
    void Delete(string str)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainKey(str[i]))
                return;
            curr->reducePrefix();
            curr = curr->get(str[i]);
        }
        curr->deleteEnd();
    }
};

int main()
{
    Trie *root = new Trie();
    root->Insert("vicky");
    root->Insert("visky");
    root->Insert("vipky");
    cout << root->Count_Prefix("vi") << "\n";
    root->Delete("vipky");
    cout << root->Count_Prefix("vi") << "\n";
    return 0;
}