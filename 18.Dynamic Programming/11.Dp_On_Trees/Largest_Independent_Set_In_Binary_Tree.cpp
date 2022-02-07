#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
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

int Largest_Independent_Set(node *root, bool isInclude)
{
    if (root == nullptr)
        return 0;
    int include = 0, exculude = 0;
    if (!isInclude)
        include = 1 + Largest_Independent_Set(root->left, true) + Largest_Independent_Set(root->right, true);
    exculude = Largest_Independent_Set(root->left, false) + Largest_Independent_Set(root->right, false);
    return max(include, exculude);
}

int main()
{
    node *root = nullptr;
    root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->left->right->left = new node(70);
    root->left->right->right = new node(80);
    root->right->right = new node(60);

    cout << Largest_Independent_Set(root, false) << "\n";
    return 0;
}