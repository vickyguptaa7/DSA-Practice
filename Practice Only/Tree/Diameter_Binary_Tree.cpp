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

int Diameter(TreeNode*root)// T.C-> O(n^2)
{
    if(!root)return 0;
    int lh=Height(root->left);
    int rh=Height(root->right);

    return max(lh+rh,max(Diameter(root->left),Diameter(root->right)));
}

int Diameter_Opt(TreeNode*root,int*Max)
{
    if(!root)return 0;
    int lh=Diameter_Opt(root->left,Max);
    int rh=Diameter_Opt(root->right,Max);
    *Max=max(*Max,lh+rh);
    return 1+max(lh,rh);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    Traversal(root);    
    int Max=0;
    Diameter_Opt(root,&Max);
    cout<<endl<<Max<<endl;
    return 0;
}