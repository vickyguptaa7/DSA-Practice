#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> Common_Element_Brute(int **arr, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool check_1 = true;
        for (int j = 0; j < n; j++)
        {
            bool check_2 = false;
            for (int k = 0; k < n; k++)
            {
                if (arr[0][i] == arr[j][k])
                {
                    check_2 = true;
                    break;
                }
            }
            if (!check_2)
            {
                check_1 = false;
                break;
            }
        }
        if (check_1)
        {
            ans.push_back(arr[0][i]);
        }
    }
    return ans;
}

bool Binary_Search(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

vector<int> Common_Element_Better(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        sort(arr[i], arr[i] + m);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 1; j < n; j++)
        {
            if (!Binary_Search(arr[j], m, arr[0][i]))
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            ans.push_back(arr[0][i]);
        }
    }
    return ans;
}

vector<int> Common_Element_Better_Better(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        sort(arr[i], arr[i] + m);
    }

    int iterr[n] = {0};
    int maxEle = 0;
    vector<int> res;
    while (true)
    {
        maxEle = 0;
        bool isAllSet = 1;
        for (int i = 0; i < n; i++)
        {
            if (iterr[i] >= n)
            {
                isAllSet = 0;
                break;
            }
            maxEle = max(arr[i][iterr[i]], maxEle);
        }
        if (!isAllSet)
            break;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            while (iterr[i] < m && arr[i][iterr[i]] < maxEle)
                iterr[i]++;
            if (maxEle == arr[i][iterr[i]])
                counter++;
        }
        if (counter == n)
        {
            res.push_back(arr[0][iterr[0]]);
            iterr[0]++;
        }
    }
    return res;
}

vector<int> Common_Element_Optimized(int **arr, int n, int m)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[0][i]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (freq.find(arr[i][j]) != freq.end() && freq[arr[i][j]] != i + 1) // remove dulplicate if we are in i row then max i can be there
                freq[arr[i][j]]++;
        }
    }
    vector<int> res;
    for (auto x : freq)
    {
        if (x.second == n)
        {
            res.push_back(x.first);
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> ans = Common_Element_Optimized(arr, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
/*
4 5
1 2 3 4 5
2 4 5 8 10
3 5 7 9 11
1 3 5 7 9
*/