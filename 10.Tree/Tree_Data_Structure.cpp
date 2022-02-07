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

int main(){
    node*root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->right->right=new node(50);
    return 0;
}