#include<iostream>
#include<queue>
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

int Depth_Recursive(TreeNode*root)
{
    if(!root)return 0;
    int left=Depth_Recursive(root->left);
    int right=Depth_Recursive(root->right);
    return max(left,right)+1;
}

int Depth_Iterative(TreeNode*root)
{
    if(!root)return 0;
    queue<TreeNode*>que;
    int level=0;
    que.push(root);
    TreeNode*curr=nullptr;
    while(!que.empty())
    {
        int size=que.size();
        for(int i=0;i<size;i++)
        {
            curr=que.front();
            que.pop();
            if(curr->left)que.push(curr->left);
            if(curr->right)que.push(curr->right);
        }
        level++;
    }
    return level;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(8);
    Traversal(root);
    cout<<endl<<Depth_Recursive(root)<<endl;
    cout<<endl<<Depth_Iterative(root)<<endl;
    
    return 0;
}