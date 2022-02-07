#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST_Iterator
{
    stack<node *> st;
    bool reverse;
    void push(node *root)
    {
        for(;root!=nullptr;)
        {
            st.push(root);
            if(reverse)root=root->right;
            else root=root->left;
        }
    }

public:
    BST_Iterator(node*root,bool isReverse=false)
    {
        reverse=isReverse;
        push(root);
    }

    int next()
    {
        if(st.empty())
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        node *curr = st.top();
        st.pop();
        if(reverse)push(curr->left);
        else push(curr->right);
        return curr->data;
    }
    bool hasnext()
    {
        return !st.empty();
    }
};

void Level_Order_Traversal(node *root)
{
    if (!root)
        return;
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            node *curr = que.front();
            que.pop();
            cout << curr->data << " ";
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
    cout<<endl;
}

void Inorder(node*root,vector<int>&ans)
{
    if(!root)return;
    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
}

bool Pair_Sum_In_Array(node*root,int sum)// T.C->O(n) And S.C->O(n)
{
    vector<int>arr;
    Inorder(root,arr);
    Print(arr);
    int i=0,j=arr.size()-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==sum)return 1;
        else if(arr[i]+arr[j]>sum)j--;
        else i++;
    }
    return 0;
}

bool Pair_Sum(node*root,int sum)// T.C->O(N) And S.C->O(H)
{
    BST_Iterator strt=BST_Iterator(root,0);
    BST_Iterator last=BST_Iterator(root,1);
    int f=strt.next();
    int l=last.next();
    while(f<l)
    {
        if(f+l==sum)
        return true;
        else if(f+l>sum)l=last.next();
        else f=strt.next();
    }
    return 0;
}

int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(5);
    root->left->right = new node(9);
    root->right->right = new node(60);
    root->right->left = new node(15);
    Level_Order_Traversal(root);
    cout<<Pair_Sum_In_Array(root,25)<<endl;
    cout<<Pair_Sum(root,65)<<endl;
    return 0;
}