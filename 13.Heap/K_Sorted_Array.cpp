#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> Sort_K_Sorted_Array_Brute(int *arr, int n)
{
    vector<int> narr(arr, arr + n);
    sort(narr.begin(), narr.end());
    return narr;
}

vector<int> Sort_K_Sorted_Array_Opt(int *arr, int n, int k)
{
    vector<int> narr;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k + 1);
    for (int i = k + 1; i < n; i++)
    {
        narr.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while (pq.size()>0)
    {
        narr.push_back(pq.top());
        pq.pop();
    }
    return narr;
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Print(Sort_K_Sorted_Array_Brute(arr, n));
    Print(Sort_K_Sorted_Array_Opt(arr, n, k));

    return 0;
}