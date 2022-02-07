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

int Find_Path(node*root,int  val,vector<int>&path)
{
    if(!root)return false;

    if(root->key==val)
    {
        path.push_back(root->key);
        return true;
    }

    bool ln=Find_Path(root->left,val,path);
    if(ln)
    {
        path.push_back(root->key);
        return true;
    }

    bool rn=Find_Path(root->right,val,path);
    if(rn)
    {
        path.push_back(root->key);
        return true;
    }
    return false;
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    vector<int>path;
    Find_Path(root,40,path);
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;

    return 0;
}