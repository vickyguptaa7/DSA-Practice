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

int Maximum_Path_Sum(node *root, int &res)
{
    if (root == nullptr)
        return 0;
    int Left_Sum = Maximum_Path_Sum(root->left, res);
    int Right_Sum = Maximum_Path_Sum(root->right, res);
    int temp = max(max(Left_Sum, Right_Sum) + root->data, root->data);
    int answer = max(temp, root->data + Left_Sum + Right_Sum);
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
    root->right->left = new node(-6);
    root->right->right = new node(-7);
    root->left->right->left = new node(50);
    int res = 0;
    Maximum_Path_Sum(root, res);
    cout << res << "\n";
    return 0;
}