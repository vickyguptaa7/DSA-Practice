#include<iostream>
#include<vector>
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

int Path(node*root,int  val,vector<int>&path)
{   
    if(!root)return false;
    if(root->key==val)
    {
        path.push_back(root->key);
        return true;
    }
    bool left=Path(root->left,val,path);
    if(left)
    {
        path.push_back(root->key);
        return true;
    }

    bool right=Path(root->right,val,path);
    if(right)
    {
        path.push_back(root->key);
        return true;
    }
    return false;
}

int Lowest_Common_Ancestor(node*root,int num1,int num2)
{
    vector<int> p1,p2;
    Path(root,num1,p1);
    Path(root,num2,p2);

    int n1=(p1.size()<p2.size())?p1.size():p2.size();
    for(int i=0;i<n1;i++)
    {
        if(p1[i]==p2[i])
        {
            return p2[i];
        }
    }
    return -1;
}

node* Lowest_Common_Ancestor_Optimally(node*root,int num1,int num2)
{
    if(!root)return nullptr;

    if(root->key==num1||root->key==num2)
    {
        return root;
    }
    node*left=Lowest_Common_Ancestor_Optimally(root->left,num1,num2);
    node*right=Lowest_Common_Ancestor_Optimally(root->right,num1,num2);
    if(left&&right)
    {
        return root;
    }
    return (left)?left:right;
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60); 
    root->right->right = new node(70);
    node*r1=Lowest_Common_Ancestor_Optimally(root,60,70);
    cout<<r1->key<<endl;
    return 0;
}