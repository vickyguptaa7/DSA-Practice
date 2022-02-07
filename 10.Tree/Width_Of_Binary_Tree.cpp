#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

void Pre_Traversal(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Pre_Traversal(root->left);
    Pre_Traversal(root->right);
}

int Width_Of_Binary_Tree(node*root)
{
    if(!root)return 0;
    queue<pair<node*,int>>que;
    que.push({root,0});
    int Max=0;
    while(!que.empty())
    {
        int size=que.size();
        int f=0,l=0,mmin=que.front().second;
        for(int i=0;i<size;i++)
        {
            node*curr=que.front().first;
            int no=que.front().second-mmin;
            que.pop();
            if(i==0)f=no;
            if(i==size-1)l=no;
            if(curr->left)que.push({curr->left,2*no+1});
            if(curr->right)que.push({curr->right,2*no+2});
        }
        Max=max(Max,l-f+1);
    }
    return Max;
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    root->left->left->left=new node(8);
    root->right->right->right=new node(9);
    Pre_Traversal(root);
    cout<<endl<<Width_Of_Binary_Tree(root)<<endl;
    return 0;
}