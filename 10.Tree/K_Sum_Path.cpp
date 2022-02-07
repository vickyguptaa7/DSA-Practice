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

void Calc(node*root,int k,vector<vector<int>>ans)
{
    
}

void K_Sum_Path(node*root,int k,vector<vector<int>>ans)
{
    if(!root)return;
    if(sum==k)
    
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<vector<int>>ans;
    vector<int>row;
    K_Sum_Path(root,row,0,7,ans);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}