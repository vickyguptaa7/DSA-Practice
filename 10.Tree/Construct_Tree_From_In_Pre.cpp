#include<iostream>
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

node* Construct_Tree(int pre[],int in[],int i,int n)
{
    static int preindex=0;
    if(i>n)return nullptr;

    node*root=new node(pre[preindex++]);
    int j=i;
    for(j;j<=n;j++)
    {
        if(root->key==in[j])break;
    }
    root->left=Construct_Tree(pre,in,i,j-1);
    root->right=Construct_Tree(pre,in,j+1,n);
    
    return root;
}

void Level_Order_Traversal(node*root)
{
    queue<node*>que;
    que.push(root);
    while(!que.empty())
    {
        int size=que.size();
        for(int i=0;i<size;i++)
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
int main(){
    int n;
    cin>>n;
    int pre[n],in[n];
    cout<<"Enter Preorder : \n";
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }

    cout<<"Enter Inorder : \n";
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    Level_Order_Traversal(Construct_Tree(pre,in,0,n-1));
    
    return 0;
}