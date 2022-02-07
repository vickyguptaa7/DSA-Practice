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

int Size_Of_Binary_Tree(node*root)
{
    int size=0;
    if(!root)return size;
    size+=Size_Of_Binary_Tree(root->left);
    size++;
    size+=Size_Of_Binary_Tree(root->right);
    return size;
}

int Size_Other_Way(node*root)
{
    int size=0;
    if(!root)return size;
    return Size_Other_Way(root->right)+Size_Other_Way(root->left)+1;
}

int main(){
    node*root=new node(10);
    root->left=new node(20);
    root->left->left=new node(30);
    root->left->right=new node(40);
    root->right=new node(50);
    root->right->right=new node(60);
    root->right->left=new node(70);
    cout<<Size_Other_Way(root)<<endl;
    return 0;
}