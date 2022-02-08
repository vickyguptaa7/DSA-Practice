#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *helper(int &ps, int pe, int is, int ie, vector<int> &preorder, vector<int> &inorder)
{
    if (ps > pe || is > ie)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[ps++]);
    int index = is;
    for (int i = is; i <= ie; i++)
    {
        if (inorder[i] == preorder[ps - 1])
        {
            index = i;
            break;
        }
    }
    root->left = helper(ps, pe, is, index - 1, preorder, inorder);
    root->right = helper(ps, pe, index + 1, ie, preorder, inorder);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int arrayLen = preorder.size() - 1;
    int ps = 0;
    return helper(ps, arrayLen, 0, arrayLen, preorder, inorder);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> in;
    if (root == nullptr)
        return in;
    stack<TreeNode *> node_st;
    node_st.push(root);
    TreeNode *curr = nullptr;
    while (!node_st.empty())
    {
        curr = node_st.top();
        node_st.pop();
        in.push_back(curr->val);

        if (curr->left)
        {
            node_st.push(curr->left);
        }
        if (curr->right)
        {
            node_st.push(curr->right);
        }
    }
    reverse(in.begin(), in.end());
    return in;
}

int main()
{
    vector<int> in = {3, 9, 20, 15, 7};
    vector<int> pre = {9, 3, 15, 20, 7};
    inorderTraversal(buildTree(pre, in));
    return 0;
}