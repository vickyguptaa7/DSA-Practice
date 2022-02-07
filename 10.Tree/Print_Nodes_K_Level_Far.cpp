#include <iostream>
#include <vector>
#include <queue>
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

void Traversal(node *root)
{
    if (!root)
        return;

    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            cout << que.front()->key << " ";
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            que.pop();
        }
        cout << endl;
    }
}

void K_Level_Down(node *root, int k, node *block, vector<int> &ans)
{
    if (!root || k < 0 || root == block)
    {
        return;
    }
    if (k == 0)
        ans.push_back(root->key);
    K_Level_Down(root->left, k - 1, block, ans);
    K_Level_Down(root->right, k - 1, block, ans);
}

bool Root_To_Node(node *root, int val, vector<node *> &path)
{
    if (!root)
        return 0;
    if (root->key == val)
    {
        path.push_back(root);
        return 1;
    }

    int chk1 = Root_To_Node(root->left, val, path);
    if (chk1)
    {
        path.push_back(root);
        return 1;
    }
    int chk2 = Root_To_Node(root->right, val, path);
    if (chk2)
    {
        path.push_back(root);
        return 1;
    }
    return 0;
}

void Node_K_Level_Far(node *root, int val, int k)
{
    vector<node *> path;
    vector<int>ans;
    Root_To_Node(root, val, path);
    for (int i = 0; i < path.size() && i <= k; i++)
    {
        K_Level_Down(path[i], k - i, (i == 0) ? nullptr : path[i - 1], ans);
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int K_level_far_Opt(node *root, int val, int k, vector<int> &ans)
{
    if (!root)
        return -1;
    if (root->key == val)
    {
        K_Level_Down(root, k - 0, nullptr, ans);
        return 1;
    }

    int ld = K_level_far_Opt(root->left, val, k, ans);
    if (ld!=-1)
    {
        K_Level_Down(root, k - ld, root->left, ans);
        return 1 + ld;
    }
    int rd = K_level_far_Opt(root->right, val, k, ans);
    if (rd!=-1)
    {
        K_Level_Down(root, k - rd, root->right, ans);
        return 1 + rd;
    }
    return -1;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->right->right->left = new node(10);
    root->right->right->right = new node(11);

    Traversal(root);
    cout << endl;
    vector<int>ans;
    K_level_far_Opt(root, 5, 3,ans);
    
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}