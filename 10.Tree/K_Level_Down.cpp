#include<iostream>
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

void K_Level_Down(node*root,int k)
{
    if(!root||k<0)
    {
        return;
    }
    if(k==0)cout<<root->key<<" ";
    K_Level_Down(root->left,k-1);
    K_Level_Down(root->right,k-1);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(13);
    
    K_Level_Down(root,1);
    return 0;
}