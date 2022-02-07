#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int Helper(TreeNode *root, int ans)
{
    if (root == nullptr)
        return 0;
    ans = ((ans * 2) + root->val);
    if (!root->left && !root->right)
        return ans;
    return Helper(root->left, ans) +
           Helper(root->right, ans);
}
int sumRootToLeaf(TreeNode *root)
{
    int ans = 0;
    return Helper(root, ans);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    // root->left->left->left = new TreeNode(6);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout << sumRootToLeaf(root) << "\n";
    return 0;
}