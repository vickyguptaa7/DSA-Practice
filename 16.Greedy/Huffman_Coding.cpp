#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left, *right;
    Node(char val, int fq = 0)
    {
        data = val;
        freq = fq;
        left = nullptr;
        right = nullptr;
    }
};
class mycmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void Encode(Node *root, string code, unordered_map<char, string> &hcode)
{
    if (root == nullptr)
        return;
    if (!root->left && !root->right)
    {
        hcode[root->data] = code;
        return;
    }
    Encode(root->left, code + '0', hcode);
    Encode(root->right, code + '1', hcode);
}

string Decode_Using_Hcode_Map(string Compressed, unordered_map<char, string> hcode)
{
    string Decompressed, helper;
    unordered_map<string, char> dehcode;
    for (auto x : hcode)
    {
        dehcode[x.second] = x.first;
    }
    for (int i = 0; i < Compressed.length(); i++)
    {
        helper += Compressed[i];
        if (dehcode.find(helper) != dehcode.end())
        {
            Decompressed += dehcode[helper];
            helper = "";
        }
    }
    return Decompressed;
}

void Decode_Tree_Helper(Node *root, string &Decompressed, string Compressed, int &i)
{
    if (root == nullptr)
        return;
    if (!root->left && !root->right)
    {
        Decompressed += root->data;
        return;
    }
    i++;
    if (Compressed[i] == '0')
        Decode_Tree_Helper(root->left, Decompressed, Compressed, i);
    else
        Decode_Tree_Helper(root->right, Decompressed, Compressed, i);
}

string Decode_Using_Tree(string Compressed, Node *root)
{
    int i = -1,len=Compressed.length();
    string Decompressed;
    while (i < len-1)
    {
        Decode_Tree_Helper(root, Decompressed, Compressed, i);
    }
    return Decompressed;
}

void Huffman_Coding(string str)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
    }
    priority_queue<Node *, vector<Node *>, mycmp> pq;
    for (auto x : freq)
    {
        Node *newnode = new Node(x.first, x.second);
        pq.push(newnode);
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node *root = pq.top();
    pq.pop();
    unordered_map<char, string> hcode;
    Encode(root, "", hcode);
    string Compressed;
    for (int i = 0; i < str.length(); i++)
    {
        Compressed += hcode[str[i]];
    }
    string Decompressed = Decode_Using_Tree(Compressed, root);
    cout << Compressed << endl;
    cout << Decompressed << endl;
}

int main()
{
    string str;
    getline(cin, str);
    Huffman_Coding(str);
    return 0;
}