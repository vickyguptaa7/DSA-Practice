#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    string val;
    node()
    {
        left = nullptr;
        right = nullptr;
    }
};

void inorder(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void Level_Order_Traversal(node*root)
{
    queue<node*>que;
    que.push(root);
    while(!que.empty())
    {
        int size=que.size();
        for(int i=0;i<size;i++)
        {
            node*curr=que.front();
            que.pop();
            cout<<curr->val<<" ";
            if(curr->left)que.push(curr->left);
            if(curr->right)que.push(curr->right);
        }
        cout<<endl;
    }
}

int main(){
    node*root;
    node k,b,v;
    root=&v;
    v.val="v";
    k.val="i";
    b.val="c";
    root->left=&k;
    root->right=&b;
    inorder(root);
    node a,e,c,d;
    root->left->left=&a;
    root->left->right=&e;
    root->right->left=&c;
    root->right->right=&d;
    inorder(root);
    return 0;
}