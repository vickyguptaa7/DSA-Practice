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

bool Check_Mirror(node*root1,node*root2)
{
    if(!root1&&!root2)return 1;
    
    if(!root1||!root2)return 0;   
    
    int r1=Check_Mirror(root1->left,root2->right);
    if(!r1)return 0;
    int r2=Check_Mirror(root1->right,root2->left);
    if(!r2)return 0;

    if(root1->key==root2->key)
    {
        return 1;
    }
    else return 0;
}

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

int main(){
    node *root1 = new node(10);
    root1->left = new node(20);
    root1->right = new node(30);
    root1->left->left = new node(40);
    root1->left->right = new node(50);
    root1->right->left = new node(60);
    root1->right->right = new node(70);

    Level_Order_Traversal(root1);

    node *root2 = new node(10);
    root2->left = new node(30);
    root2->right = new node(20);
    root2->left->left = new node(70);
    root2->left->right = new node(60);
    root2->right->left = new node(50);
    root2->right->right = new node(40);

    cout<<endl;

    Level_Order_Traversal(root2);

    cout<<endl;

    cout<<Check_Mirror(root1,root2)<<endl;
    return 0;
}