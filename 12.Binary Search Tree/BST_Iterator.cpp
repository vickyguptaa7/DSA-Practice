#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
    cout << endl
         << endl;
    BST_Iterator start=BST_Iterator(root,0);
    BST_Iterator last=BST_Iterator(root,1);
    cout<<start.hasnext()<<endl;
    cout<<start.next()<<endl;
    cout<<last.hasnext()<<endl;
    cout<<last.next()<<endl;
    return 0;
}