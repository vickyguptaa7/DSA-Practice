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

int Hight(node*root)
{
    if(!root)return 0;

    int lr=Hight(root->left);
    int rr=Hight(root->right);
    return max(lr,rr)+1;
}

int Diameter_Of_BT_Brute_Force(node*root) 
{
    if(!root)return 0;

    int dleft=Hight(root->left);
    int dright=Hight(root->right);
    return max(dright+dleft+1,max(dleft,dright));
}
int Max=0;
int Diameter_Of_BT_Optemised(node*root)
{
    if(!root)return 0;
    
    int lr=Diameter_Of_BT_Optemised(root->left);
    int rr=Diameter_Of_BT_Optemised(root->right);
    
    Max=max(Max,lr+rr+1);
    return max(lr,rr)+1;
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<Hight(root)<<endl;
    cout<<Diameter_Of_BT_Brute_Force(root)<<endl;
    cout<<Diameter_Of_BT_Optemised(root)<<endl;
    return 0;
}