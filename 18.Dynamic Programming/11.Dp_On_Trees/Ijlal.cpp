#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
//function for printing BT Parent->left->right
void display(node *root)
{
    if (root == NULL)
    {
        cout << "Empty!!";
        return;
    }

    if (root->left != NULL)
        display(root->left);
    cout << root->data << " ";
    if (root->right != NULL)
        display(root->right);
}

//function for initial filling of BST
node *Insert(int element, node *root)
{
    node *ptr;
    if (root == NULL)
    {
        ptr = new node;
        ptr->data = element;
        ptr->left = ptr->right = NULL;
        return ptr;
    }
    else
    {
        if (element < root->data)
            root->left = Insert(element, root->left);
        else if (element > root->data)
            root->right = Insert(element, root->right);
    }

    return ptr;
}

node *inorderPredecessor(node *root)
{
}

node *inorderSuccessor(node *root)
{
}

node *Remove(int element, node *root)
{
    //element not found
    if (root == NULL)
        return NULL;

    if (element == root->data)
    {
        node *ptr = root;
        //leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete ptr;
            return NULL;
        }
        //only left child
        else if (root->right == NULL && root->left != NULL)
        {
            delete ptr;
            return root->left;
        }
        //only right child
        else if (root->left == NULL && root->right != NULL)
        {
            delete ptr;
            return root->right;
        }
    }
    //element might be in left BST
    else if (element < root->data)
        root->left = Remove(element, root->left);
    //element might be in right BST
    else if (element > root->data)
        root->right = Remove(element, root->right);
}

int main()
{
    system("cls");
    node *root = NULL;

    int arr[] = {20, 11, 30, 5, 25, 35, 6};
    //         20
    //       /   \
    //     11    30
    //   /      /  \
    //  5     25   35
    //   \
    //    6

    //initial filling of BST
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        root = Insert(arr[i], root);

    cout << "Before Deletion: ";
    display(root);

    // root = Remove(11, root);

    // cout << "\nAfter Deletion: ";
    //  display(root);
}