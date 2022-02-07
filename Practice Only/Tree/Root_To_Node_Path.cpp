#include<iostream>
#include <vector>
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

bool Path(TreeNode*root,int val,vector<int>&res)
{
    if(!root)return 0;
    if(root->data==val)
    {
        res.push_back(root->data);
        return 1;
    }
    int chk1=Path(root->left,val,res);
    if(chk1)
    {
        res.push_back(root->data);
        return 1;
    }
    int chk2=Path(root->right,val,res);
    if(chk2)
    {
        res.push_back(root->data);
        return 1;
    }
    return 0;
}

void Traversal(TreeNode *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    Traversal(root->left);
    Traversal(root->right);
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Traversal(root);
    vector<int>res;
    cout<<endl;
    if(Path(root,2,res))for(int i=0;i<res.size();i++)cout<<res[res.size()-1-i]<<" ";
    else cout<<"Not Found"<<endl;
    cout<<endl;
    return 0;
}