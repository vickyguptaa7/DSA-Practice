#include<iostream>
#include<vector>
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

int Root_To_Node(TreeNode*root,int val,vector<TreeNode*>&path)
{
    if(!root)return 0;
    
    if(root->data==val)
    {
        path.push_back(root);
        return 1;
    }
    if(Root_To_Node(root->left,val,path))
    {
        path.push_back(root);
        return 1;
    }
    if(Root_To_Node(root->right,val,path))
    {
        path.push_back(root);
        return 1;
    }
    return 0;
}

int Depth_Of_Tree(TreeNode*root,TreeNode* block)
{
    if(!root||root==block)return 0;
    int ld=Depth_Of_Tree(root->left,block);
    int rd=Depth_Of_Tree(root->right,block);
    return 1+max(ld,rd);
}

int Time_To_Burn(TreeNode*root,int val)
{
    vector<TreeNode*>path;
    int Max=0;
    Root_To_Node(root,val,path);
    for(int i=0;i<path.size();i++)
    {
        Max=max(Max,Depth_Of_Tree(root,(i==0)?nullptr:path[i-1])+i-1);
    }
    return Max;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right->right->left = new TreeNode(10);
    root->right->right->right = new TreeNode(11);

    Traversal(root);  
    cout<<endl<<Time_To_Burn(root,1)<<endl;
    return 0;
}