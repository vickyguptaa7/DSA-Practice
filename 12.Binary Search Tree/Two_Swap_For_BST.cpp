#include <iostream>
#include <queue>
#include <vector>
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

void Print(vector<int>arr)
{
    cout<<endl;
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
}

void Inorder(node*root,vector<int>&ans)
{
    if(!root)return;
    Inorder(root->left,ans);
    ans.push_back(root->key);
    Inorder(root->right,ans);
}

void Fix_By_Swap_In_Array(vector<int>&arr)
{
    Print(arr);
    vector<int>ans;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i-1]>arr[i])
        {
            if(ans.size()==0)ans.push_back(i-1);
            else ans.push_back(i);
        }
    }
    if(ans.size()==1)ans[1]=arr.size()-1;
    
    int temp=arr[ans[0]];
    arr[ans[0]]=arr[ans[1]];
    arr[ans[1]]=temp;
    Print(arr);
}

void Fix_BST(node*root,node*&prev,node*&first,node*&second)
{
    if(!root)return;
    Fix_BST(root->left,prev,first,second);
    if(prev!=nullptr&&root->key<prev->key)
    {
        if(first==nullptr)first=prev;
        second=root;
    }
    prev=root;
    Fix_BST(root->right,prev,first,second);
}

void Fix_BST_With_Two_Swap(node*root)
{
    node*prev=nullptr,*first=nullptr,*second=nullptr;
    Fix_BST(root,prev,first,second);
    int key=first->key;
    first->key=second->key;
    second->key=key;
}

int main()
{
    node *root = new node(60);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(5);
    root->left->right = new node(9);
    root->right->right = new node(10);
    root->right->left = new node(15);
    Level_Order_Traversal_m2(root);
    vector<int>arr;
    Inorder(root,arr);
    Print(arr);
    // Fix_By_Swap_In_Array(arr);
    cout<<endl;
    Fix_BST_With_Two_Swap(root);
    Level_Order_Traversal_m2(root);
    arr.clear();
    Inorder(root,arr);
    Print(arr);
    return 0;
}