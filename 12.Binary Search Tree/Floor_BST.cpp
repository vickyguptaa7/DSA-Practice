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
void Level_Order_Traversal_m2(node*root)
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
            cout<<curr->key<<" ";
            if(curr->left)que.push(curr->left);
            if(curr->right)que.push(curr->right);
        }
        cout<<endl;
    }
}

int Floor_BST(node*root,int val)
{
    int answer=-1;
    node*curr=root;
    while(curr)
    {
        if(curr->key==val)
        {
            return val;
        }
        else if(curr->key<val)
        {
            answer=curr->key;
            curr=curr->right;
        }
        else 
        {
            curr=curr->left;
        }
    }
    return answer;
}

int main(){
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(5);
    root->left->right = new node(9);
    root->right->right = new node(60);
    root->right->left=new node(15);
    Level_Order_Traversal_m2(root);
    cout<<endl<<Floor_BST(root,7)<<endl;
    return 0;
}