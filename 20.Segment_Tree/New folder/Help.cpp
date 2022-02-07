#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode
{
    TreeNode *left, *right;
    int val;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};
vector<int> postorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    stack<TreeNode *> s;
    vector<int> res;
    if (curr == NULL)
    {
        return res;
    }
    do
    {
        while (curr)
        {
            if (curr->right)
            {
                s.push(curr->right);
            }
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if (!s.empty() && curr->right == s.top())
        {
            s.pop();
            s.push(curr);
            curr = curr->right;
        }
        else
        {
            res.push_back(curr->val);
            curr = NULL;
        }
    } while (!s.empty());
    return res;
}

void Post(TreeNode *root)
{
    if (root == nullptr)
        return;
    Post(root->left);
    Post(root->right);
    cout << root->val << " ";
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Post(root);
    cout << "\n";
    vector<int> ans = postorderTraversal(root);
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}