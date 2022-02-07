#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node*next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};

vector<int> Merge_K_Sorted_Array_Better(vector<vector<int>> arr_list)
{
    vector<int> new_list;
    for (int i = 0; i < arr_list.size(); i++)
    {
        for (int j = 0; j < arr_list[i].size(); j++)
        {
            new_list.push_back(arr_list[i][j]);
        }
    }
    sort(new_list.begin(), new_list.end());
    return new_list;
}

vector<int> Merge_K_Sorted_Array_Optimal(vector<vector<int>> arr_list)
{
    vector<int> new_list;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < arr_list.size(); i++)
    {
        pq.push({arr_list[i][0], {i, 0}});
    }
    while (!pq.empty())
    {
        int i = pq.top().second.first, j = pq.top().second.second;
        new_list.push_back(pq.top().first);
        pq.pop();
        if (arr_list[i].size() > j + 1)
        {
            pq.push({arr_list[i][j + 1], {i, j + 1}});
        }
    }
    return new_list;
}

vector<int> Merge_Sorted_Array(vector<int> a1, vector<int> a2)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < a1.size() && j < a2.size())
    {
        if (a1[i] < a2[j])
        {
            ans.push_back(a1[i]);
            i++;
        }
        else
        {
            ans.push_back(a2[j]);
            j++;
        }
    }
    while (i < a1.size())
    {
        ans.push_back(a1[i]);
        i++;
    }
    while (j < a2.size())
    {
        ans.push_back(a2[i]);
        j++;
    }
    return ans;
}

vector<int> Merge_K_Sorted_Brute(vector<vector<int>> arr_list)
{
    vector<int> ans;
    for (int i = 0; i < arr_list.size(); i++)
    {
        ans = Merge_Sorted_Array(arr_list[i], ans);
    }
    return ans;
}

// Linked List Merge

Node *mergeKLists(Node *arr[], int K) 
{
    priority_queue<pair<int, Node *>,
                   vector<pair<int, Node *>>,
                   greater<pair<int, Node *>>>
        pq;

    for (int i = 0; i < K; i++)
    {
        pq.push({arr[i]->data, arr[i]});
    }
    Node *newnode = pq.top().second, *prev = pq.top().second;
    pq.pop();
    if (prev->next != nullptr)
    {
        pq.push({prev->next->data, prev->next});
    }
    while (!pq.empty())
    {
        Node *curr = pq.top().second;
        prev->next = curr;
        prev = prev->next;
        pq.pop();
        if (curr->next != nullptr)
        {
            pq.push({curr->next->data, curr->next});
        }
    }
    return newnode;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> arr(m);
        for (int j = 0; j < m; j++)
            cin >> arr[j];
        arr_list.push_back(arr);
    }
    // Print(Merge_K_Sorted_Array_Better(arr_list));
    // Print(Merge_K_Sorted_Brute(arr_list));
    Print(Merge_K_Sorted_Array_Optimal(arr_list));

    return 0;
}