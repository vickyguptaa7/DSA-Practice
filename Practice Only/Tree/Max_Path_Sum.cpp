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

int Height_Sum(TreeNode*root)
{
    if(!root)return 0;
    int lsum=Height_Sum(root->left);
    int rsum=Height_Sum(root->right);
    return max(lsum,rsum)+root->data;
}

int Max_Path_Sum(TreeNode*root)// T.C-> O(n^2)
{
    if(!root)return 0;
    int lsum=Height_Sum(root->left);
    int rsum=Height_Sum(root->right);
    
    return max(lsum+rsum+root->data,max(Max_Path_Sum(root->left),Max_Path_Sum(root->right)));
}

int Max_Path_Sum_Opt(TreeNode*root,int*Max)
{
    if(!root)return 0;
    int lsum=Max_Path_Sum_Opt(root->left,Max);
    int rsum=Max_Path_Sum_Opt(root->right,Max);
    *Max=max(*Max,lsum+rsum+root->data);
    return max(lsum,rsum)+root->data; 
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
    Max_Path_Sum_Opt(root,&Max);
    cout<<endl<<Max<<endl; 
    return 0;
}