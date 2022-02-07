#include <iostream>
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

void Level_Order_Traversal(node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        int count = que.size();
        for (int i = 0; i < count; i++)
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

int isComplete_Iterative(node *root)
{
    if (!root)
        return 1;
    queue<node *> que;
    que.push(root);
    bool chk = false;
    while (que.size())
    {
        node *curr = que.front();
        que.pop();
        if (curr->left)
        {
            if(chk==true)return false;
            que.push(curr->left);
        }
        else
            chk = true;
        if(curr->right)
        {
            if(chk==true)return false;
            que.push(curr->right);
        }
        else chk=true;
    }
    return true;
}

int Count_Node(node*root)
{
    if(!root)return 0;
    int lcount=Count_Node(root->left);
    int rcount=Count_Node(root->right);
    return lcount+rcount+1;
}

bool isComplete_Recursive(node*root,int index,int number_node)
{
    if(!root)return  true;
    if(index>=number_node)return false;
    if(!isComplete_Recursive(root->left,2*index+1,number_node))return false;
    if(!isComplete_Recursive(root->right,2*index+2,number_node))return false;
    return true;
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

    Level_Order_Traversal(root);
    cout << endl
         << endl;
    cout<<isComplete_Iterative(root)<<endl;
    cout<<isComplete_Recursive(root,0,Count_Node(root))<<endl;
    return 0;
}