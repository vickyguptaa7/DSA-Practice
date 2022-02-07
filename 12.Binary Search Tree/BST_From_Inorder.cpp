#include <iostream>
#include <queue>
#include <vector>
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
void Level_Order_Traversal_m2(node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            que.pop();
            cout << curr->key << " ";
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
        cout << endl;
    }
}

void Preorder(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Inorder(node *root, vector<int> &ans)
{
    if (!root)
        return;
    Inorder(root->left, ans);
    ans.push_back(root->key);
    Inorder(root->right, ans);
}

node *Form_BST(vector<int> arr, int s, int e)
{
    if (s > e)
        return nullptr;
    int mid = s + (e - s) / 2;
    node *root = new node(arr[mid]);
    root->left = Form_BST(arr, s, mid - 1);
    root->right = Form_BST(arr, mid + 1, e);
    return root;
}

node *Form_BST_From_Inorder(vector<int> arr)
{
    int count = 0;
    return Form_BST(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node *root = Form_BST_From_Inorder(arr);
    Level_Order_Traversal_m2(root);
    cout << endl;
    Preorder(root);
    vector<int> in;
    Inorder(root, in);
    Print(in);
    return 0;
}