#include <iostream>
#include <stack>
#include <map>
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

int Maximum_Sum_Of_Non_Adjacent_Nodes(node *root, map<node *, int> &dp)
{
    if (!root)
        return 0;

    if (dp[root])
        return dp[root];

    int withNode = root->key;
    if (root->left)
    {
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->left->right, dp);
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->left->left, dp);
    }
    if (root->right)
    {
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->right->right, dp);
        withNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->right->left, dp);
    }

    int withoutNode = 0;
    withoutNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->left, dp);
    withoutNode += Maximum_Sum_Of_Non_Adjacent_Nodes(root->right, dp);
    return dp[root] = max(withNode, withoutNode);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    int s = 0;
    map<node *, int> dp;
    cout << Maximum_Sum_Of_Non_Adjacent_Nodes(root, dp);

    return 0;
}