#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

void Pre_Traversal(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Pre_Traversal(root->left);
    Pre_Traversal(root->right);
}

vector<vector<int>> Vertical_Order_Traversal(node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<pair<node *, int>> que;
    unordered_map<int, vector<int>> umap;
    que.push({root, 0});
    int Max=0,Min=0;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            node*curr=que.front().first;
            int lvl=que.front().second;
            que.pop();
            Max=max(Max,lvl);
            Min=min(Min,lvl);
            umap[lvl].push_back(curr->key);
            if(curr->left)que.push({curr->left,lvl-1});
            if(curr->right)que.push({curr->right,lvl+1});
        }
    }
    for(int i=Min;i<=Max;i++)
    {
        ans.push_back(umap[i]);
    }
    return ans;
}

void Print(vector<vector<int>>mat)
{
    cout<<endl;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    Pre_Traversal(root);
    Print(Vertical_Order_Traversal(root));
    return 0;
}