#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left,*right;
    node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

bool Binary_Tree_isHeap_Iterative(node*root)
{
    if(!root)return 1;
    queue<node*>que;
    que.push(root);
    int chk=false;
    while(que.size())
    {
        node*curr=que.front();
        que.pop();
        if(curr->left)
        {
            if(chk==true||curr->data<curr->left->data)return false;
            que.push(curr->left);
        }
        else chk=true;
        
        if(curr->right)
        {
            if(chk==true||curr->data<curr->right->data)return false;
            que.push(curr->right);
        }
        else chk=true;
    }
    return true;
}

bool isHeap(node*root)
{
    if(!root)return 1;
    if(root->left&&root->left->data>root->data)return false;
    if(root->right&&root->right->data>root->data)return false;
    return isHeap(root->left)&&isHeap(root->right);
}

int Node_Count(node*root)
{
    if(!root)return 0;
    return 1+Node_Count(root->left)+Node_Count(root->right);
}

int isComplete(node*root,unsigned int index,unsigned int total_node)
{
    if(!root)return 1;
    if(index>=total_node)return false;
    if(!isComplete(root->left,2*index+1,total_node))return false;
    if(!isComplete(root->right,2*index+2,total_node))return false;
    return true;
}

bool Binary_Tree_isHeap_Recursive(node*root)
{
    if(!root)return 1;
    int total_node=Node_Count(root);
    return (isComplete(root,0,total_node)&&isHeap(root));
}

int main(){
    node*root=new node(20);
    root->left=new node(18);
    root->right=new node(17);
    root->left->left=new node(10);
    root->left->right=new node(14);
    root->right->left=new node(12);
    root->right->right=new node(5);
    cout<<Binary_Tree_isHeap_Iterative(root)<<endl;
    cout<<Binary_Tree_isHeap_Recursive(root)<<endl;
    return 0;
}