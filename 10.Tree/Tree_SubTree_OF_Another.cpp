#include <iostream>
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

bool Check_Similar(node *root1, node *root2)
{
    if (!root1 || !root2)
        return root1 == root2;
    if (root1->key != root2->key)
        return 0;
    if (!Check_Similar(root1->left, root2->left))
        return 0;
    if (!Check_Similar(root1->right, root2->right))
        return 0;
    return 1;
}

bool Subtree_Of_Another(node *root1, node *root2)
{
    if (!root1)
        return 0;
    if (Check_Similar(root1, root2))
        return 1;
    if(Subtree_Of_Another(root1->left, root2))return 1;
    if(Subtree_Of_Another(root1->right, root2))return 1;
    return 0;
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
    node *root2 = new node(3);
    root2->left = new node(6);
    root2->right = new node(7);
    if (Subtree_Of_Another(root, root2))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}