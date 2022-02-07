#include<iostream>
#include<cmath>
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

int Depth_Of_Binary_Tree(TreeNode*root)
{
    if(!root)return 0;
    return 1+max(Depth_Of_Binary_Tree(root->left),Depth_Of_Binary_Tree(root->right));
}

int Left_Hight(TreeNode*root)
{
    int cnt=0;
    while(root)
    {
        root=root->left;
        cnt++;
    }
    return cnt;
}

int Right_Hight(TreeNode*root)
{
    int cnt=0;
    while(root)
    {
        root=root->right;
        cnt++;
    }
    return cnt;
}

int Count_Node_Complete(TreeNode*root)
{
    if(!root)return 0;
    int lh=Left_Hight(root);
    int rh=Right_Hight(root);
    if(lh==rh)
    {
        return pow(2,lh)-1;
    }
    return Count_Node_Complete(root->left)+Count_Node_Complete(root->right)+1;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);  

    cout<<endl<<Count_Node_Complete(root)<<endl;    

    return 0;
}