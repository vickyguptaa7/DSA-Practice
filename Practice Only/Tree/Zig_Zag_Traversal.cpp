#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void Traversal(TreeNode *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    Traversal(root->left);
    Traversal(root->right);
}

vector<vector<int>> Zig_Zag_Traversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> que;
    stack<TreeNode *> st;
    que.push(root);
    TreeNode *curr = nullptr;
    bool k = false;
    while (!que.empty())
    {
        int size = que.size();
        k = !k;
        vector<int> lvl;
        for (int i = 0; i < size; i++)
        {
            curr = que.front();
            que.pop();
            lvl.push_back(curr->data);
            if (k % 2 == 1)
            {
                if (curr->left)
                    st.push(curr->left);
                if (curr->right)
                    st.push(curr->right);
            }
            else
            {
                if (curr->right)
                    st.push(curr->right);
                if (curr->left)
                    st.push(curr->left);
            }
        }
        ans.push_back(lvl);
        while (!st.empty())
        {
            que.push(st.top());
            st.pop();
        }
    }
    return ans;
}

vector<vector<int>> Zig_Zag_Traversal_Optemize(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st1, st2;
    st1.push(root);
    TreeNode *curr = nullptr;
    bool check = true;
    while (!st1.empty() || !st2.empty())
    {
        int size = (st1.empty()) ? st2.size() : st1.size();
        vector<int> lvl;
        for (int i = 0; i < size; i++)
        {
            if (check)
            {
                curr = st1.top();
                st1.pop();
                if (curr->left)
                    st2.push(curr->left);
                if (curr->right)
                    st2.push(curr->right);
            }
            else
            {
                curr = st2.top();
                st2.pop();
                if (curr->right)
                    st1.push(curr->right);
                if (curr->left)
                    st1.push(curr->left);
            }
            lvl.push_back(curr->data);
        }
        ans.push_back(lvl);
        check = !check;
    }
    return ans;
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
    Traversal(root);
    vector<vector<int>> ans = Zig_Zag_Traversal_Optemize(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}