#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode
{
    TrieNode *child[2];
    TrieNode()
    {
        for (int i = 0; i < 2; i++)
            child[i] = nullptr;
    }
    bool isContainsKey(int bit)
    {
        return child[bit] != nullptr;
    }
    void put(int bit, TrieNode *root)
    {
        child[bit] = root;
    }
    TrieNode *get(int bit)
    {
        return child[bit];
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
    void Insert(int num)
    {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if (!curr->isContainsKey(bit))
            {
                curr->put(bit, new TrieNode());
            }
            curr = curr->get(bit);
        }
    }
    int getMax(int num)
    {
        TrieNode *curr = root;
        int Max_Num = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if (curr->isContainsKey(!bit)) // if Contains Opposite Bit
            {
                Max_Num = (Max_Num | (1 << i));
                curr = curr->get(!bit);
            }
            else // Does Not Contain Opposite
            {
                curr = curr->get(bit);
            }
        }
        return Max_Num;
    }
};

int Max_Xor_Of_Two_Array_Number(int arr1[], int n, int arr2[], int m)
{
    Trie *root = new Trie();
    for (int i = 0; i < n; i++)
    {
        root->Insert(arr1[i]);
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        result = max(result, root->getMax(arr2[i]));
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    cout << Max_Xor_Of_Two_Array_Number(arr1, n, arr2, m) << "\n";
    return 0;
}

/*

7
7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
*/