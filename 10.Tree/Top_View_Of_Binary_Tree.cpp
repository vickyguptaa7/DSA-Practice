#include<iostream>
#include<queue>
#include<map>
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

void Pre_Traversal(node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    Pre_Traversal(root->left);
    Pre_Traversal(root->right);
}

vector<int> Top_View(node*root)
{
    vector<int>ans;
    if(!root)return ans;
    queue<pair<node*,int>>que;
    map<int,int>map;
    que.push({root,0});
    while(!que.empty())
    {
        int size=que.size();
        while(size--)
        {
            node*curr=que.front().first;
            int lvl=que.front().second;
            que.pop();
            if(map.find(lvl)==map.end())map[lvl]=curr->key;
            if(curr->left)que.push({curr->left,lvl-1});
            if(curr->right)que.push({curr->right,lvl+1});
        }
    }
    for(auto x:map)
    {
        ans.push_back(x.second);
    }
    return ans;
}

void Print(vector<int>ans)
{
    cout<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
        node *root = new node(1);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    Pre_Traversal(root);
    Print(Top_View(root));
    return 0;
}