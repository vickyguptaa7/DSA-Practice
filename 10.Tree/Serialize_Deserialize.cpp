#include<iostream>
#include<vector>
#include<queue>
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

void Level_Order_Traversal(node*root)
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

void Serialize(node*root,vector<int> &ans)
{
    if(!root)
    {
        ans.push_back(-1); //-1 Denoting The Node Is Pointing To Null
        return;
    }
    ans.push_back(root->key);
    Serialize(root->left,ans);
    Serialize(root->right,ans);
}

node* Deserialize(vector<int> arr,int index=0)
{
    if(arr.size()==0)return nullptr;
    
    if(arr[index]==-1) return nullptr;

    node*root=new node(arr[index]);
    root->left=Deserialize(arr,index+1);
    root->right=Deserialize(arr,index+1);
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

    Level_Order_Traversal(root);
    vector<int> ans;
    Serialize(root,ans);
    cout<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}