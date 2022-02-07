#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int Check_Cntns(map<int, int> &freq)
{
    vector<int> arr;
    for (auto x : freq)
        arr.push_back(x.first);
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < n)
        {
            arr[arr[i]] = -arr[arr[i]];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            count++;
    return count;
}

int Min_Operations(int arr[], int n)
{
    map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    int counter = 0;
    int duplicate = 0;
    for (auto x : freq)
    {
        if (x.second > 1)
            duplicate += x.second;
    }
    int non_continuous = Check_Cntns(freq);

    return max(non_continuous, duplicate);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int Min = arr[0];
    for (int i = 0; i < n; i++)
        Min = min(arr[i], Min);
    for (int i = 0; i < n; i++)
        arr[i] -= Min;
    cout << Min_Operations(arr, n) << "\n";

    return 0;
}