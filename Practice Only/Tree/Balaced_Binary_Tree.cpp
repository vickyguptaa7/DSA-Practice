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

int Height(TreeNode*root)
{
    if(!root)return 0;
    return max(Height(root->left),Height(root->right))+1;
}

bool Balanced(TreeNode*root) // T.C->O(n^2)
{
    if(!root)return 1;
    int lh=Height(root->left);
    int rh=Height(root->right);
    if(abs(lh-rh)>1)return false;
    bool left=Balanced(root->left);
    bool right=Balanced(root->right);
    if(left&&right)return true;
    return false;
}

int Balanced_Opt(TreeNode*root)// T.C->O(n)
{
    if(!root)return 0;
    int lh=Balanced_Opt(root->left);
    if(lh==-1)return -1;
    int rh=Balanced_Opt(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return 0;
    return 1+max(lh,rh);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left=new TreeNode(6);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    Traversal(root);
    cout<<endl<<Balanced(root)<<endl;
    return 0;
}