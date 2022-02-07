#include<iostream>
#include<queue>
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

void Flatten_BST(node*root,node*&prev)
{
    if(!root)return;
    Flatten_BST(root->left,prev);
    prev->right=root;
    prev->left=nullptr;
    prev=root;
    Flatten_BST(root->right,prev); 
}

node*BST_Sorted_List(node*root)
{
    if(!root)return nullptr;
    node*temp=new node(0);
    node*prev=temp;
    Flatten_BST(root,prev);
    prev=temp;
    prev=prev->right;
    delete temp;
    return prev;
}

void Print_List(node*root)
{
    while(root!=nullptr)
    {
        cout<<root->key<<"->";
        root=root->right;
    }
    cout<<"Null"<<endl;
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
    Print_List(BST_Sorted_List(root));
    return 0;
}