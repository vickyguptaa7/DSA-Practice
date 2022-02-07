#include <iostream>
#include <stack>
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

void Pre_Traversal(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Pre_Traversal(root->left);
    Pre_Traversal(root->right);
}

bool isSymmetricalCheck(node *root1, node *root2)
{
    if (!root1 || !root2)
        return root1 == root2;

    bool chk1 = isSymmetricalCheck(root1->left, root2->right);
    if (!chk1)
        return 0;
    bool chk2 = isSymmetricalCheck(root1->right, root2->left);
    if (!chk2)
        return 0;
    if (root1->key != root2->key)
        return 0;

    return 1;
}

bool isSymmetrical(node *root)
{
    if (!root)
        return 1;
    return isSymmetricalCheck(root->left, root->right);
}

bool isSymmetrical_iterative(node *root)
{
    if (root == nullptr)
        return true;
    stack<node *> stack1, stack2;
    stack1.push(root);
    stack2.push(root);
    while (!stack1.empty() && !stack2.empty())
    {
        node *curr1 = stack1.top();
        node *curr2 = stack2.top();
        stack1.pop();
        stack2.pop();
        if (curr1->key != curr2->key)
            return false;
        if (curr1->right)
            stack1.push(curr1->right);
        if (curr1->left)
            stack1.push(curr1->left);

        if (curr2->left)
            stack2.push(curr2->left);
        if (curr2->right)
            stack2.push(curr2->right);
    }
    if (!stack1.empty() && !stack2.empty())
        return false;
    return true;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    Pre_Traversal(root);
    cout << endl
         << isSymmetrical(root) << endl;
    cout << endl
         << isSymmetrical_iterative(root) << endl;
    return 0;
}