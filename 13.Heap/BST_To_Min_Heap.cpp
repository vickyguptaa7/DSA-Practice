#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void Level_Traversal(node *root)
{
    cout<<endl;
    if (!root)
        return;
    queue<node *> que;
    que.push(root);
    while (que.size())
    {
        int size = que.size();
        while (size--)
        {
            node *curr = que.front();
            que.pop();
            cout << curr->data << " ";
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
        cout << endl;
    }
    cout<<endl;
}

void Inordere_Traversal(node *root, vector<int> &arr)
{
    if (!root)
        return;
    Inordere_Traversal(root->left, arr);
    arr.push_back(root->data);
    Inordere_Traversal(root->right, arr);
}

void Preorder_Traversal(node *root, vector<int> &arr, int &index)
{
    if (!root)
        return;
    root->data = arr[index++];
    Preorder_Traversal(root->left, arr, index);
    Preorder_Traversal(root->right, arr, index);
}

void BST_To_Min_Heap(node *root)
{
    if (!root)
        return;
    vector<int> arr;
    int index = 0;
    Inordere_Traversal(root, arr);
    Preorder_Traversal(root, arr, index);
}

int main()
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(2);
    root->left->right = new node(8);
    root->right->left = new node(12);
    root->right->right = new node(20);
    Level_Traversal(root);
    BST_To_Min_Heap(root);
    Level_Traversal(root);
    return 0;
}