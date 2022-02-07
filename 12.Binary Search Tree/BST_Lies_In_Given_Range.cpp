#include<iostream>
#include <vector>
#include <queue>
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

void Preorder(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int Count_In_Range(node*root,int l,int r)
{
    if(!root)return 0;
    if(root->key>=l&&root->key<=r)
    {
        return 1+Count_In_Range(root->left,l,r)+Count_In_Range(root->right,l,r);
    }
    else if(root->key<l)
    {
        return Count_In_Range(root->right,l,r);
    }
    else 
    {
        return Count_In_Range(root->left,l,r);
    }
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
    cout<<endl<<Count_In_Range(root,8,8)<<endl; 
    return 0;
}