#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int Diameter_Of_Tree(node *root, int &res)
{
    if (root == nullptr)
        return 0;
    int l_height = Diameter_Of_Tree(root->left, res);
    int r_height = Diameter_Of_Tree(root->right, res);
    int temp = 1 + max(l_height, r_height);
    int answer = max(1 + l_height + r_height, temp);
    res = max(res, answer);
    return temp;
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
    root->right->right->left = new node(8);
    int res = 0;
    Diameter_Of_Tree(root, res);
    cout << res << "\n";
    return 0;
}