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

void Calc(node *root, int k, vector<int> tmp, vector<vector<int>> &ans)
{
    if (!root)
    {
        return;
    }
    tmp.push_back(root->key);
    if (k == root->key)
    {
        ans.push_back(tmp);
    }
    Calc(root->left, k - root->key, tmp, ans);
    Calc(root->right, k - root->key, tmp, ans);
}

void K_Sum_Path(node *root, int k, vector<int> row, vector<vector<int>> &ans) // T.C -> O(n^2)
{
    if (!root)
        return;
    Calc(root, k, row, ans);
    K_Sum_Path(root->left, k, row, ans);
    K_Sum_Path(root->right, k, row, ans);
}
int K_Sum_Path_Opt(node *root, int targetSum, int sum, map<int, int> omap) // T.C -> O(n)
{
    if (!root)
        return 0;
    sum += root->key;

    int paths = 0;
    if (sum == targetSum)
        paths++;
    if (omap.count(sum - targetSum))
    {
        paths += omap[sum - targetSum];
    }
    omap[sum]++;
    paths += K_Sum_Path_Opt(root->left, targetSum, sum, omap);
    paths += K_Sum_Path_Opt(root->right, targetSum, sum, omap);
    omap[sum]--;
    return paths;
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
    vector<vector<int>> ans;
    vector<int> row;
    K_Sum_Path(root, 7, row, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    map<int, int> omap;
    cout << K_Sum_Path_Opt(root, 7, 0, omap) << "\n";
    return 0;
}