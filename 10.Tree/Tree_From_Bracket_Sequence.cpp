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

node *Tree_From_Bracket_Sequence(string s, int &iter)
{
    if (s.size() <= iter || s[iter] == ')')
    {
        iter++;
        return nullptr;
    }
    if (s[iter] == '(')
        iter++;
    string num;
    while (s[iter] >= '0' && s[iter] <= '9')
        num += s[iter++];

    node *newNode = new node(stoi(num));
    newNode->left = Tree_From_Bracket_Sequence(s, iter);
    newNode->right = Tree_From_Bracket_Sequence(s, iter);
    return newNode;
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
    int s = 0;
    Pre_Traversal(Tree_From_Bracket_Sequence("4(2(3)(1))(6(5))", s));

    return 0;
}