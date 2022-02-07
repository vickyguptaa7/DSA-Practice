#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> Four_Sum_Brute(int arr[], int n, int key) // T.C -> O(n^4)
{
    vector<vector<int>> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == key)
                    {
                        unordered_set<int> uset;
                        uset.insert(arr[i]);
                        uset.insert(arr[j]);
                        uset.insert(arr[k]);
                        uset.insert(arr[l]);
                        if (uset.size() == 4)
                        {
                            vector<int> anscol;
                            anscol.push_back(arr[i]);
                            anscol.push_back(arr[j]);
                            anscol.push_back(arr[k]);
                            anscol.push_back(arr[l]);
                            answer.push_back(anscol);
                        }
                    }
                }
            }
        }
    }
    return answer;
}

vector<vector<int>> Four_Sum_Better(int arr[], int n, int key) // T.C -> O(n^3)
{
    sort(arr, arr + n);
    vector<vector<int>> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int p = j + 1, q = n - 1;
            while (p < q)
            {
                if (arr[i] + arr[j] + arr[p] + arr[q] == key)
                {
                    unordered_set<int> uset;
                    uset.insert(arr[i]);
                    uset.insert(arr[j]);
                    uset.insert(arr[p]);
                    uset.insert(arr[q]);
                    if (uset.size() == 4)
                    {
                        vector<int> anscol;
                        anscol.push_back(arr[i]);
                        anscol.push_back(arr[j]);
                        anscol.push_back(arr[p]);
                        anscol.push_back(arr[q]);
                        answer.push_back(anscol);
                    }
                    q--;
                }
                else if (arr[i] + arr[j] + arr[p] + arr[q] > key)
                {
                    q--;
                }
                else
                {
                    p++;
                }
            }
        }
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<vector<int>> answer = Four_Sum_Brute(arr, n, k);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}