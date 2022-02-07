#include <iostream>
#include <stack>
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

void Iterative_DF_Traversal(node *root)
{
    stack<pair<node *, int>> st;
    pair<node *, int> rn = {root, 1};
    st.push(rn);
    vector<int> In, Pre, Post;

    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            Pre.push_back(st.top().first->key);
            st.top().second++;
            if (st.top().first->left)
            {
                pair<node *, int> n = {st.top().first->left, 1};
                st.push(n);
            }
        }
        else if (st.top().second == 2)
        {

            In.push_back(st.top().first->key);
            st.top().second++;
            if (st.top().first->right)
            {
                pair<node *, int> n = {st.top().first->right, 1};
                st.push(n);
            }
        }
        else
        {
            Post.push_back(st.top().first->key);
            st.pop();
        }
    }
    int n = Pre.size();
    cout << "\nPreorder -> "
         << " ";
    for (int i = 0; i < n; i++)
    {
        cout << Pre[i] << " ";
    }

    cout << "\nInorder -> "
         << " ";
    for (int i = 0; i < n; i++)
    {
        cout << In[i] << " ";
    }

    cout << "\nPostorder -> "
         << " ";
    for (int i = 0; i < n; i++)
    {
        cout << Post[i] << " ";
    }
}

void Level_Order_Traversal_m1(node*root)
{
    queue<node*>que;
    que.push(root);
    que.push(nullptr);
   
    while(que.size()>1)
    {
        node*curr=que.front();
        que.pop();
        if(!curr)
        {
            que.push(nullptr);
            cout<<endl;
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

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    Level_Order_Traversal_m1(root); //method 1
    cout<<endl<<endl;
    Level_Order_Traversal_m2(root); // mehtod 2 
    return 0;
}