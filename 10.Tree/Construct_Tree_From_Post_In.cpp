#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> Level_Order_Traversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int n = que.size();
        vector<int> lvl;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            lvl.push_back(node->data);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        ans.push_back(lvl);
    }
    return ans;
}

TreeNode *Convert_To_Tree(vector<int> post, vector<int> in, int ps, int pe, int is, int ie)
{
    if (is > ie)
        return nullptr;
    int idx = is;
    while (in[idx] != post[pe])
        idx++;
    int colse = idx - is; //count_of_left_sub_tree_element
    TreeNode *root = new TreeNode(post[pe]);
    root->left = Convert_To_Tree(post, in, ps, ps + colse-1, is, idx - 1);
    root->right = Convert_To_Tree(post, in, ps + colse , pe - 1, idx + 1, ie);
    return root;
}
// Post 4 5 2 6 7 3 1
// In   4 2 5 1 6 3 7
int main()
{
    int n;
    cin >> n;
    vector<int> post(n), in(n);
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    TreeNode *root = Convert_To_Tree(post, in, 0, n - 1, 0, n - 1);
    vector<vector<int>> ans = Level_Order_Traversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}