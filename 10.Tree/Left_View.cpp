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

void Left_View(node*root) // Iterative Method
{
    queue<node*>que;
    que.push(root);
    while(!que.empty())
    {
        int n=que.size();
        for(int i=0;i<n;i++)
        {
            node*curr=que.front();
            que.pop();
            if(i==0)cout<<curr->key<<" ";
            if(curr->left)que.push(curr->left);
            if(curr->right)que.push(curr->right);
        }
    }
}

void Left_View_Recursive(node*root,int lvl=1)
{
    static int i=0;
    if(!root)return;
    if(i<lvl)
    {
        i++;
        cout<<root->key<<" ";
    }
    Left_View_Recursive(root->left,lvl+1);
    Left_View_Recursive(root->right,lvl+1);
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);
    root->right->right->right=new node(80);

    Level_Order_Traversal_m2(root);
    cout<<endl<<endl;
    Left_View_Recursive(root);
    return 0;
}