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
            child[i] = nullptr;
    }
    bool isContainsKey(char ch)
    {
        return (child[ch - 'a'] != nullptr);
    }
    void put(char ch, TrieNode *root)
    {
        child[ch - 'a'] = root;
    }
    TrieNode *get(char ch)
    {
        return child[ch - 'a'];
    }
    void setEnd()
    {
        isEnd = true;
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
    void Insert(string str, TrieNode *&root)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i] - 'a';
            if (!curr->isContainsKey(str[i]))
            {
                curr->put(str[i], new TrieNode());
            }
            curr = curr->get(str[i]);
        }
        curr->setEnd();
    }
    bool Search(string str, TrieNode *&root)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainsKey(str[i]))
            {
                return false;
            }
            curr = curr->get(str[i]);
        }
        return curr->isEnd; // This Condition Because It May Be Only Prefix the Word We Are Seraching By Doing This We Insuring The Word Is Present Its Not Just Prefix
    }
    bool Starts_With(string prefix, TrieNode *&root) // Check Prefix
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!curr->isContainsKey(prefix[i]))
            {
                return false;
            }
            curr->get(prefix[i]);
        }
        return true; // We have Finded The Prefix
    }
    TrieNode *Delete(string str, TrieNode *root, int s)
    {
        if (root == nullptr)
            return nullptr;
        if (str.length() == s)
        {
            root->isEnd = false;
            if (root->isEmpty())
            {
                delete (root);
                root = nullptr;
            }
            return root;
        }
        int index = str[s] - 'a';
        root->child[index] = Delete(str, root->child[index], s + 1);
        if (root->isEmpty() && root->isEnd == false)
        {
            delete (root);
            root = nullptr;
        }
        return root;
    }
};

int main()
{
    TrieNode *root = new TrieNode();
    root->Insert("vicky", root);
    cout << root->Search("vicky", root) << "\n";
    root->Delete("vicky", root, 0);
    cout << root->Search("vicky", root) << "\n";
    return 0;
}