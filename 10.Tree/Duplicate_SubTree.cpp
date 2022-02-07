#include<iostream>
#include<map>
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

void In_Traversal(node*root)
{
    if(!root)return;
    cout<<root->key<<" ";
    In_Traversal(root->left);
    In_Traversal(root->right);
}

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

string Duplicate_Subtree(node*root,map<string,int>&mp,vector<node*>&ans)
{
    if(!root)return "";
    string str="(";
    str+=Duplicate_Subtree(root->left,mp,ans);
    str+=to_string(root->key);
    str+=Duplicate_Subtree(root->right,mp,ans);
    str+=")";
    if(mp[str]==1)ans.push_back(root);
    mp[str]++;
    return str;
}

vector<node*>Duplicates(node*root)
{
    vector<node*>ans;
    if(!root)return ans;
    map<string,int>mp;
    Duplicate_Subtree(root,mp,ans);
    return ans;
}

void Print(vector<node*>ans)
{
    for(int i=0;i<ans.size();i++)
    {
        In_Traversal(ans[i]);
        cout<<endl;
    }
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    root->right->left = new node(2);
    root->right->right = new node(4);
    // root->left->left->left = new node(8);
    // root->left->left->right = new node(9);
    // root->right->right->left = new node(11);
    // root->right->right->right = new node(11);  
    root->right->left->left=new node(4);
    Print(Duplicates(root));
    return 0;
}