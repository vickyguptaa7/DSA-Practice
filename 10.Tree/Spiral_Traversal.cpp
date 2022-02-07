#include <iostream>
#include <queue>
#include <stack>
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

void Spiral_Traversal_m1(node *root) //Stack And Queue
{
    queue<node *> que;
    stack<int> st;
    que.push(root);
    int i = 0;
    while (!que.empty())
    {
        int size = (que.empty()) ? st.size() : que.size();
        for (int j = 0; j < size; j++)
        {
            node*curr=que.front();
            que.pop();
            if(i%2)
            st.push(curr->key);
            else
            cout<<curr->key<<" ";

            if (curr->left)
                que.push(curr->left);
            if (curr->right)
                que.push(curr->right);
        }
        if(i%2)
        {
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        i++;
        cout << endl;
    }
}

void Spiral_Traversal(node*root)
{
    stack<node*>st1;
    stack<node*>st2;
    st1.push(root);
    bool i=true;
    while(!st1.empty()||!st2.empty())
    {
        int size=(st1.empty())?st2.size():st1.size();
        for(int j=0;j<size;j++)
        {
            if(i)
            {
                node*curr=st1.top();
                st1.pop();
                cout<<curr->key<<" ";
                if(curr->left)st2.push(curr->left);
                if(curr->right)st2.push(curr->right);
            }
            else
            {
                node*curr=st2.top();
                st2.pop();
                cout<<curr->key<<" ";
                if(curr->right)st1.push(curr->right);
                if(curr->left)st1.push(curr->left);
            }
        }
        i=!i;
        cout<<endl;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right->left->left = new node(12);
    root->right->left->right = new node(13);
    root->right->right->left = new node(14);
    root->right->right->right = new node(15);
    

    Spiral_Traversal(root);
    return 0;
}