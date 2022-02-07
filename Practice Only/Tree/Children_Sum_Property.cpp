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

int Child_Sum_Property(TreeNode*root)
{
    if(!root||(!root->left&&!root->right))return 1;
    int sum=0;
    if(root->left)
    sum+=root->left->data;
    if(root->right)
   sum+=root->right->data;
    if(sum!=root->data)return 0;

    return Child_Sum_Property(root->left)&&Child_Sum_Property(root->right);
}

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(1);  
    cout<<endl<<Child_Sum_Property(root)<<endl;
    return 0;
}