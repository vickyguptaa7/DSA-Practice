#include <iostream>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
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

void In_Traversal(node *root, unordered_set<int> &uset)
{
    if (!root)
        return;
    In_Traversal(root->left, uset);
    uset.insert(root->key);
    In_Traversal(root->right, uset);
}

void Count_Pair_1(node *root, unordered_set<int> uset, int sum, int &count)
{
    if (!root)
        return;
    if (uset.find(sum - root->key) != uset.end())
        count++;
    Count_Pair_1(root->left, uset, sum, count);
    Count_Pair_1(root->right, uset, sum, count);
}

int Pairs_In_BST_1(node *root1, node *root2, int sum) // T.C -> O(n+m)  S.C -> O(m)
{
    unordered_set<int> uset;
    In_Traversal(root2, uset);
    int Count = 0;
    Count_Pair_1(root1, uset, sum, Count);
    return Count;
}

bool Check_Pairs_2(node *root, int sum)
{
    if (!root)
        return 0;
    if (root->key > sum)
    {
        return Check_Pairs_2(root->left, sum);
    }
    else if (root->key < sum)
    {
        return Check_Pairs_2(root->right, sum);
    }
    else
    {
        return 1;
    }
}

void Count_Pair_2(node *root1, node *root2, int sum, int &count)
{
    if (!root1)
        return;
    if (Check_Pairs_2(root2, sum - root1->key))
        count++;
    Count_Pair_2(root1->left, root2, sum, count);
    Count_Pair_2(root1->right, root2, sum, count);
}

int Pairs_In_BST_2(node *root1, node *root2, int sum) // T.C -> O(n*h)  S.C -> O(h)
{
    int count = 0;
    Count_Pair_2(root1, root2, sum, count);
    return count;
}

int Pairs_In_BST_3_Opt(node *root1, node *root2, int sum)// T.C -> O(m+n) S.C -> O(h1+h2)
{
    if (!root1 || !root2)
        return 0;
    stack<node *> st1, st2;
    int cnter = 0;
    while (true)
    {
        while (root1 != nullptr)
        {
            st1.push(root1);
            root1 = root1->left;
        }

        while (root2 != nullptr)
        {
            st2.push(root2);
            root2 = root2->right;
        }

        if (st1.empty() || st2.empty())
            break;

        int t1 = st1.top()->key;
        int t2 = st2.top()->key;

        if (t1 + t2 == sum)
        {
            cnter++;
            root1 = st1.top()->right;
            root2 = st2.top()-> left;
            st1.pop();
            st2.pop();
        }
        else if (t1 + t2 > sum)
        {
            root2 = st2.top()->left;
            st2.pop();
        }
        else
        {
            root1 = st1.top()->right;
            st1.pop();
        }
    }
    return cnter;
}

int main()
{
    node *root2 = new node(10);
    root2->left = new node(8);
    root2->right = new node(20);
    root2->left->left = new node(5);
    root2->left->right = new node(9);
    root2->right->right = new node(60);
    root2->right->left = new node(15);
    Level_Order_Traversal(root2);
    cout << endl;
    node *root1 = new node(20);
    root1->left = new node(10);
    root1->right = new node(40);
    root1->left->left = new node(4);
    root1->left->right = new node(12);
    root1->right->right = new node(45);
    root1->right->left = new node(25);
    Level_Order_Traversal(root1);

    cout << endl
         << Pairs_In_BST_1(root1, root2, 75) << endl;
    cout << endl
         << Pairs_In_BST_2(root1, root2, 75) << endl;

    cout << endl
         << Pairs_In_BST_3_Opt(root1, root2, 75) << endl;

    return 0;
}