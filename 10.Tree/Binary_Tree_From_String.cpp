#include<iostream>
#include<queue>
#include<stack>
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

void Level_Order_Traversal(node *root)
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

node* Tree(string str)
{
    node*root=new node(stoi(str.substr(0,1)));
    str.erase(0,1);
    stack<node*>st;
    st.push(root);
    bool chk=1;
    while(str.length())
    {
        if(str[0]=='(')
        {
            str.erase(0,1);
        }
        else if(str[0]==')')
        {
            str.erase(0,1);
            if(chk==0)chk=1;
            else chk=0;
        }
        else // 4(5(1)(2))(6(3)(4))
        {
            if(chk)
            {
                node*curr=st.top();
                curr->left=new node(stoi(str.substr(0,1)));
                st.push(curr->left);
            }
            else
            {
                st.pop();
                node*curr=st.top();
                curr->right=new node(stoi(str.substr(0,1)));
                st.push(curr->right);
            }
            str.erase(0,1);
        }
    }
    return root;
}

int main(){
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    // Level_Order_Traversal(root);
    return 0;
}