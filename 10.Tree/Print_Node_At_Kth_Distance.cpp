#include<iostream>
#include<queue>

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

void Level_Order_Traversal_m1(node*root)
{
    queue<node*> que;
    que.push(root);
    que.push(nullptr);
    while(que.size()>1)
    {
        node*curr=que.front();
        que.pop();
        if(!curr)
        {
            cout<<endl;
            que.push(nullptr);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left)que.push(curr->left);
        if(curr->right)que.push(curr->right);
    }
    
}

void Level_Order_Traversal_m2(node*root)
{
    queue<node*>que;
    que.push(root);
    while(!que.empty())
    {
        int count=que.size();
        for(int i=0;i<count;i++)
        {
            node*curr=que.front();
            que.pop();
            cout<<curr->key<<" ";
            if(curr->left)que.push(curr->left);
            if(curr->right)que.push(curr->right);
        }
        cout<<endl;
    }
}

void Kth_Node(node*root,int k)
{
    if(root==nullptr)return;
    if(k==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        Kth_Node(root->left,k-1);
        Kth_Node(root->right,k-1);
    }
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    Level_Order_Traversal_m2(root);
    cout<<endl<<endl;
    Kth_Node(root,2);
    return 0;
}