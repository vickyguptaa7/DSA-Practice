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

void Traversal(node *root)
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
            cout << que.front()->key << " ";
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            que.pop();
        }
        cout << endl;
    }
}

vector<vector<int>> Diagonal_Traversal(node*root)
{
    vector<vector<int>>ans;
    if(!root)return ans;
    queue<node*>que;
    que.push(root);
    while(!que.empty())
    {
        vector<int>diagonal;
        int size=que.size();
        while(size--)
        {
            node*curr=que.front();
            que.pop();
            while(curr)
            {
                if(curr->left)
                que.push(curr->left);
                diagonal.push_back(curr->key);
                curr=curr->right;
            }
        }
        ans.push_back(diagonal);
    }
    return ans;
}

void Print(vector<vector<int>>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->right->right->left = new node(10);
    root->right->right->right = new node(11);  
    Print(Diagonal_Traversal(root));
    return 0;
}