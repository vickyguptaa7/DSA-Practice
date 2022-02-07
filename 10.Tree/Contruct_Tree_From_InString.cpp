#include<iostream>
#include<queue>
using namespace std;
struct node
{
    char key;
    node *left;
    node *right;
    node(char k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

node* Construct_Tree(char pre[],char in[],int i,int n)
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

void In_Order(node*root)
{
    if(root==nullptr)
    {
        return;
    }
    In_Order(root->left);
    cout<<root->key<<" ";
    In_Order(root->right);
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
    char pre[n+1],in[n+1];
    cout<<"Enter Preorder : \n";
    int i;
    for( i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    pre[i]='\0';
    cout<<"Enter Inorder : \n";
    for(i=0;i<n;i++)
    {
        cin>>in[i];
    }
    in[i]='\0';
    In_Order(Construct_Tree(pre,in,0,n-1));
    
    return 0;
}