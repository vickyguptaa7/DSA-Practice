#include<iostream>
using namespace std;

struct node
{
    int key;
    node*left;
    node*right;
    node(int val)
    {
        key=val;
        left=nullptr;
        right=nullptr;
    }
};

void Inorder_Traversal(node*root)
{
    if(!root)
    {
        return;
    }
    Inorder_Traversal(root->left);
    cout<<root->key<<" ";
    Inorder_Traversal(root->right);
}

void Preorder_Traversal(node*root)
{
    if(!root)return;
    cout<<root->key<<" ";
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}

void Postorder_Traversal(node*root)
{
    if(!root)return;
    Postorder_Traversal(root->left);
    Postorder_Traversal(root->right);
    cout<<root->key<<" ";
}

int main(){
    node*root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->right->right=new node(50);
    Inorder_Traversal(root);
    cout<<endl;
    Preorder_Traversal(root);
    cout<<endl;
    Postorder_Traversal(root);
    return 0;
}