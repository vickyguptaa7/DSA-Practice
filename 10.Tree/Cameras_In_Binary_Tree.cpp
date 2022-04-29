#include <iostream>
#include <vector>
#include <map>
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

int Cameras_In_Binary_Tree(node *root, int &cameraCount)
{
    /*

    -1 -> need a camera
    0  -> have a camera
    1  -> covered by camera (by child not by parent camera)

    */
    if (!root)
        return 1;
    int left = Cameras_In_Binary_Tree(root->left, cameraCount);
    int right = Cameras_In_Binary_Tree(root->right, cameraCount);
    if (left == -1 || right == -1)
    {
        cameraCount++;
        return 0; // have a camera
    }
    if (left == 1 && right == 1)
    {
        return -1; // need  a camera
    }

    return 1; // covered by child no need of camera
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int cameraCount = 0;
    if (Cameras_In_Binary_Tree(root, cameraCount) == -1)
    {
        cameraCount++;
    }
    cout << cameraCount << "\n";
    return 0;
}