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

void ksmallest(node *root, int k, int &indx, int &ans)
{
    if (!root)
        return;
    ksmallest(root->left, k, indx, ans);
    if (indx == k)
    {
        ans = root->key;
        indx++;
        return;
    }
    else
        indx++;
    ksmallest(root->right, k, indx, ans);
}
int KthSmallestElement(node *root, int K)
{
    int ans = -1, indx = 1;
    ksmallest(root, K, indx, ans);
    return ans;
}

void klargest(node *root, int k, int &indx, int &ans)
{
    if (!root)
        return;
    klargest(root->right, k, indx, ans);
    if (indx == k)
    {
        ans = root->key;
        indx++;
        return;
    }
    else
        indx++;
    klargest(root->left, k, indx, ans);
}
int kthLargest(node *root, int K)
{
    int ans = 0, indx = 1;
    klargest(root, K, indx, ans);
    return ans;
}

int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(5);
    root->left->right = new node(9);
    root->right->right = new node(60);
    root->right->left = new node(15);
    Level_Order_Traversal_m2(root);
    cout<<endl<<KthSmallestElement(root,3)<<endl;
    cout<<endl<<kthLargest(root,3)<<endl;

    return 0;
}