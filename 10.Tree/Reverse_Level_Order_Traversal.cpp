#include <iostream>
#include <algorithm>
#include <queue>
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

vector<int> Reverse_Level_Order_Traversal(node *root) // with stack and que
{
    queue<node *> que;
    stack<int> st;
    vector<int> ans;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            st.push(curr->key);
            que.pop();
            if (curr->right)
                que.push(curr->right);
            if (curr->left)
                que.push(curr->left);
        }
    }

    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

vector<int> Reverse_Level_Order_Traversal_only(node *root) // with que only
{
    queue<node *> que;
    vector<int> ans;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = que.front();
            ans.push_back(curr->key);
            que.pop();
            if (curr->right)
                que.push(curr->right);
            if (curr->left)
                que.push(curr->left);
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;
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

    vector<int> ans = Reverse_Level_Order_Traversal_only(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}