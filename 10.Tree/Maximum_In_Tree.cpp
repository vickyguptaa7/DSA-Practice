#include<iostream>
using namespace std;

struct node
{
    int key;
    node*left;
    node*right;
    node(int k)
    {
        key=k;
        left=right=nullptr;
    }
};

int Maximum_Element_In_Tree(node*root)
{
    if(!root)return INT_MIN;

    int lmax=Maximum_Element_In_Tree(root->left);
    int rmax=Maximum_Element_In_Tree(root->right);
    int tmax=max(max(lmax,rmax),root->key);
    return tmax;
}



int main(){
    node*root=new node(10);
    root->left=new node(20);
    root->left->left=new node(130);
    root->left->right=new node(40);
    root->right=new node(50);
    root->right->right=new node(60);
    root->right->left=new node(70);

    cout<<Maximum_Element_In_Tree(root)<<endl;
    return 0;
}