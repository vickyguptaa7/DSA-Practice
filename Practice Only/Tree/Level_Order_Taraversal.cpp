#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node
{
    int data;
    node*left;
    node*right;
    node(int val)
    {
        data=val;
        right=nullptr;
        left=nullptr;
    }
};

void Pre_Traversal(node*root)
{
    if(root==nullptr)return;
    cout<<root->data<<" ";
    Pre_Traversal(root->left);
    Pre_Traversal(root->right);
}

vector<vector<int>> Level_Order_Traversal(node*root)
{
    vector<vector<int>>ans;
    if(!root)return ans;
    queue<node*>que;
    que.push(root);

    while(!que.empty())
    {
        int n=que.size();
        vector<int>lvl;
        for(int i=0;i<n;i++)
        {
            node*node=que.front();
            que.pop();
            lvl.push_back(node->data);
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);
        }
        ans.push_back(lvl);
    }
    return ans;
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    Pre_Traversal(root);
    cout<<endl;
    vector<vector<int>>lvl=Level_Order_Traversal(root);

    for(int i=0;i<lvl.size();i++)
    {
        for(int j=0;j<lvl[i].size();j++)cout<<lvl[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}