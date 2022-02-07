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

TreeNode* Lowest_Common_Anncestor(TreeNode*root,int a,int b)
{
    if(!root||root->data==a||root->data==b)return root;
    TreeNode* left=Lowest_Common_Anncestor(root->left,a,b);
    TreeNode* right=Lowest_Common_Anncestor(root->right,a,b);
    if(left==nullptr)return right;
    else if(right==nullptr)return left;
    else return root;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<endl<<Lowest_Common_Anncestor(root,3,7)->data<<endl;

    return 0;
}