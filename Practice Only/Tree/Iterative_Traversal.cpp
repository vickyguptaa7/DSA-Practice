#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

vector<int> Iterative_Preorder(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *curr = nullptr;
    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        if (curr->right)
            st.push(curr->right);

        if (curr->left)
            st.push(curr->left);
    }
    return ans;
}

vector<int> Iterative_Inorder(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                return ans;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

vector<int> Iterative_Postorder(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *curr = nullptr;
    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        if (curr->left)
            st.push(curr->left);
        if (curr->right)
            st.push(curr->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void All_Traversal(TreeNode *root)
{
    if (!root)
        return;
    stack<pair<TreeNode *, int>> st;
    vector<int> pre, in, post;
    pair<TreeNode *, int> n = {root, 1};
    st.push(n);
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            pre.push_back(st.top().first->data);
            st.top().second++;
            if (st.top().first->left)
            {
                pair<TreeNode *, int> p = {st.top().first->left, 1};
                st.push(p);
            }
        }
        else if (st.top().second == 2)
        {
            in.push_back(st.top().first->data);
            st.top().second++;
            if (st.top().first->right)
            {
                pair<TreeNode *, int> p = {st.top().first->right, 1};
                st.push(p);
            }
        }
        else
        {
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    Print(pre);
    Print(in);
    Print(post);
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
        in.push_back(curr->data);

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
    TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    Traversal(root);
    // All_Traversal(root);
    vector<int> ans = inorderTraversal(root);
    cout << "\n";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}