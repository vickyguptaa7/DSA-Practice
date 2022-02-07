#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node*next;
    node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        next=nullptr;
    }
};

void Level_Order_Traversal_m2(node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            que.pop();
            cout << curr->key << " ";
            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
        cout << endl;
    }
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Inorder(node *root, vector<int> &ans)
{
    if (!root)
        return;
    Inorder(root->left, ans);
    ans.push_back(root->key);
    Inorder(root->right, ans);
}

void Populate(node*&root,node*&prev)
{
    if(!root)return;
    Populate(root->left,prev);
    if(prev)prev->next=root;
    prev=root;
    Populate(root->right,prev);
}

void Populate_Traversal(node*root)
{
    node*curr=root;
    while(curr->left!=nullptr)curr=curr->left;
    while(curr)
    {
        cout<<curr->key<<" ";
        curr=curr->next;
    }
}

void Populate_Inorder_Succession(node*&root)
{
    if(!root)return;
    node*prev=nullptr;
    Populate(root,prev);
    Populate_Traversal(root);
}

int main(){
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(5);
    root->left->right = new node(9);
    root->right->right = new node(60);
    root->right->left = new node(15);
    Level_Order_Traversal_m2(root);
    vector<int> arr;
    Inorder(root, arr); 
    Print(arr); 
    Populate_Inorder_Succession(root); 
    return 0;
}