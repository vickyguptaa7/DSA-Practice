#include<iostream>
#include<queue>
#include<math.h>
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

void Level_Order_Traversal(node*root)
{
    queue<node*>que;
    que.push(root);
    while(!que.empty())
    {
        int n=que.size();
        for(int i=0;i<n;i++)
        {
            node*curr=que.front();
            que.pop();
            cout<<curr->key<<" ";
            if(curr->left)que.push(curr->left);
            if(curr->right)que.push(curr->right);
        }
        cout<<endl;
    }
}

int Count_Node_OF_Complete_Binary_Tree_Brute(node*root)
{
    if(!root)return 0;
    int lc=Count_Node_OF_Complete_Binary_Tree_Brute(root->left);
    int rc=Count_Node_OF_Complete_Binary_Tree_Brute(root->right);
    return lc+rc+1;
}

int Count_Node_Of_Complete_Binary_Tree_Optimal(node*root)
{
    if(!root)return 0;
    int lc=0,rc=0;
    node*curr=root;
    while(curr)
    {
        lc++;
        curr=curr->left;
    }
    curr=root;
    while (curr)
    {
        rc++;
        curr=curr->right;
    }

    if(lc==rc)
    {
        return pow(2,lc)-1;
    }
    else
    {
        return Count_Node_Of_Complete_Binary_Tree_Optimal(root->left)
        + Count_Node_Of_Complete_Binary_Tree_Optimal(root->right)+1;
    }
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60); 
    root->right->right = new node(70);
    root->left->left->left=new node(80);
    Level_Order_Traversal(root);
    cout<<Count_Node_Of_Complete_Binary_Tree_Optimal(root)<<endl;
    return 0;
}