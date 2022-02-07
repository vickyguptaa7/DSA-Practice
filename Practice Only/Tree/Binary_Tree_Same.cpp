#include<iostream>
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

bool Check_BT(TreeNode*root,TreeNode*root2)
{
    if(!root||!root2)return root==root2;

    bool chk1=Check_BT(root->left,root2->left);
    if(chk1==0)return 0;
    bool chk2=Check_BT(root->right,root2->right);
    if(chk2==0)return 0;

    if(root->data!=root2->data)return 0;
    return 1;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    Traversal(root);
    cout<<endl;
    Traversal(root2); 
    cout<<endl<<Check_BT(root,root2)<<endl;
    return 0;
}