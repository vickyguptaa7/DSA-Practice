#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &mhp, int n, int i)
{
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && mhp[smallest] < mhp[left])
        smallest = left;
    if (right < n && mhp[smallest] < mhp[right])
        smallest = right;
    if (smallest != i)
    {
        swap(mhp[smallest], mhp[i]);
        heapify(mhp, n, smallest);
    }
}
void build_max_heap(vector<int> &mhp, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        heapify(mhp, n, i);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> mhp;
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        mhp.push_back(num);
    }
    for (int j = 0; j < b.size(); j++)
    {
        int num = b[j];
        mhp.push_back(num);
    }
    build_max_heap(mhp, m + n);
    return mhp;
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<vector<int>> arr_list;
    int n,m;
    cin >> n>>m;
    vector<int>a(n),b(m);
    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < m; i++)cin>>b[i];
    Print(mergeHeaps(a,b,n,m));
    return 0;
}