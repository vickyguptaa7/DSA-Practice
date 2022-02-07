#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Longest_Bitonic_Subseq_Optemize(int arr[], int n)
{
    vector<int> lds, lis, Tail;
    lds.push_back(1);
    lis.push_back(1);
    Tail.push_back(arr[0]);
    // LIS
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > Tail.back())
        {
            Tail.push_back(arr[i]);
            lis.push_back(Tail.size());
        }
        else
        {
            int indx = upper_bound(Tail.begin(), Tail.end(), arr[i]) - Tail.begin();
            if (indx > 0 && Tail[indx - 1] == arr[i])
            {
                lis.push_back(indx);
                continue;
            }
            Tail[indx] = arr[i];
            lis.push_back(indx + 1);
        }
    }
    // LDS
    Tail.clear();
    Tail.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > Tail.back())
        {
            Tail.push_back(arr[i]);
            lds.push_back(Tail.size());
        }
        else
        {
            int indx = upper_bound(Tail.begin(), Tail.end(), arr[i]) - Tail.begin();
            if (indx > 0 && Tail[indx - 1] == arr[i])
            {
                lds.push_back(indx);
                continue;
            }
            Tail[indx] = arr[i];
            lds.push_back(indx + 1);
        }
    }
    reverse(lds.begin(), lds.end());
    int longest_bitonic = 0;
    for (int i = 0; i < n; i++)
    {
        longest_bitonic = max(longest_bitonic, lis[i] + lds[i] - 1);
    }
    return longest_bitonic;
}

int Longest_Bitonic_Subseq(int arr[], int n)
{
    vector<int> lds(n, 1), lis(n, 1);
    // LIS -> Longest Increasing Subseq
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    /*
    LDS-> Longest Decreasing Subseq
    If We Reverse The Given Array And Find LIS It Will Be Equal
    To LDS of The Original Array.

    Arr ->| 10 | 22 | 9 | 33 | 21 | 50 | 41 | 60 | 80 | 3 |
    LIS ->| 1  | 2  | 1 |  3 | 2  | 4  | 4  | 5  | 6  | 1 |
    LDS ->| 3  |  3 | 2 |  3 | 2  | 3  | 2  | 2  | 2  | 1 |  <-LIS From backward
    */
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    int longest_bitonic = 0;
    for (int i = 0; i < n; i++)
    {
        longest_bitonic = max(longest_bitonic, lis[i] + lds[i] - 1);
    }
    return longest_bitonic;
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
    cout << Longest_Bitonic_Subseq_Optemize(arr, n) << "\n";
    return 0;
}
/*
10
10 22 9 33 21 50 41 60 80 3
*/