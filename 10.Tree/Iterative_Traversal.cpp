#include <iostream>
#include <stack>
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

void Iterative_Inorder(node *root)
{
    stack<node *> st;
    node *curr = root;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}

void Iterative_Preorder(node *root)
{
    stack<node *> st;
    node *curr = root;

    while (curr || !st.empty())
    {
        while (curr)
        {
            cout << curr->key << " ";
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}

void Iterative_Using_Pair(node *root)
{
    stack<pair<node *, int>> st;

    vector<int> inorder, postorder, preorder;

    pair<node *, int> rtp = {root, 1};
    st.push(rtp);

    while (!st.empty())
    {

        if (st.top().second == 1)
        {
            preorder.push_back(st.top().first->key);

            st.top().second++;

            if (st.top().first->left)
            {
                pair<node *, int> p = {st.top().first->left, 1};
                st.push(p);
            }
        }
        else if (st.top().second == 2)
        {
            inorder.push_back(st.top().first->key);
            st.top().second++;
            if (st.top().first->right)
            {
                pair<node *, int> p = {st.top().first->right, 1};
                st.push(p);
            }
        }
        else if (st.top().second == 3)
        {
            postorder.push_back(st.top().first->key);
            st.pop();
        }
    }
    int n=inorder.size();
    cout<<endl<<"Preorder -> ";
    for(int i=0;i<n;i++)
    {
        cout<<preorder[i]<<" ";
    }
    cout<<endl<<"Inorder -> ";
    for(int i=0;i<n;i++)
    {
        cout<<inorder[i]<<" ";
    }
    cout<<endl<<"Postorder -> ";
    for(int i=0;i<n;i++)
    {
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->left->left = new node(30);
    root->left->right = new node(40);
    root->right = new node(50);
    root->right->right = new node(60);
    root->right->left = new node(70);

    Iterative_Using_Pair(root);
    return 0;
}