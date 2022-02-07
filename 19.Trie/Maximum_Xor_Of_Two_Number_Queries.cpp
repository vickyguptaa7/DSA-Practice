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
        {
            child[i] = nullptr;
        }
    }
    bool isContainKey(int bit)
    {
        return child[bit] != nullptr;
    }
    TrieNode *get(int bit)
    {
        return child[bit];
    }
    void put(int bit, TrieNode *root)
    {
        child[bit] = root;
    }
    bool isEmpty()
    {
        for (int i = 0; i < 2; i++)
        {
            if (child[i] != nullptr)
                return false;
        }
        return true;
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
            if (!curr->isContainKey(bit))
            {
                curr->put(bit, new TrieNode());
            }
            curr = curr->get(bit);
        }
    }
    int getMax(int num)
    {
        TrieNode *curr = root;
        if (curr->isEmpty())
            return -1;
        int Max_Num = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            if (curr->isContainKey(!bit))
            {
                Max_Num = (Max_Num | 1 << i);
                curr = curr->get(!bit);
            }
            else
                curr = curr->get(bit);
        }
        return Max_Num;
    }
};

bool mycomp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

vector<int> Max_Xor_Of_Two_Numbers_Queries(int arr[], int n, vector<pair<int, int>> &queries, int q)
{
    sort(arr, arr + n);
    vector<vector<int>> Qers;
    for (int i = 0; i < q; i++)
    {
        vector<int> Quer = {queries[i].first, queries[i].second, i};
        Qers.push_back(Quer);
    }
    sort(Qers.begin(), Qers.end(), mycomp);
    vector<int> result(q);
    int itr_arr = 0;
    Trie *root = new Trie();
    for (int i = 0; i < q; i++)
    {
        int xi = Qers[i][0];
        int ri = Qers[i][1];
        int index = Qers[i][2];
        while (itr_arr < n && arr[itr_arr] <= ri)
        {
            root->Insert(arr[itr_arr++]);
        }
        result[index] = root->getMax(xi);
    }
    return result;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++)
    {
        int x, r;
        cin >> x >> r;
        queries.push_back({x, r});
    }
    vector<int> ans = Max_Xor_Of_Two_Numbers_Queries(arr, n, queries, q);
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}