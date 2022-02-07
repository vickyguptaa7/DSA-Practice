//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        if (n > m)
        {
            return findMedian(brr, m, arr, n);
        }

        int low = 0, high = n;
        while (low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;

            int min1, min2, max1, max2;
            min1 = (mid1 == n) ? INT_MAX : arr[mid1];
            min2 = (mid2 == m) ? INT_MAX : brr[mid2];
            max1 = (mid1 == 0) ? INT_MIN : arr[mid1 - 1];
            max2 = (mid2 == 0) ? INT_MIN : brr[mid2 - 1];

            if (min1 >= max2 && min2 >= max1)
            {
                if ((n + m) % 2 == 0)
                {
                    return (min(min1, min2) + max(max1, max2))/2;
                }
                else
                {
                    return max(max1, max2);
                }
            }
            else if (min1 < max2)
            {
                low = mid1 + 1;
            }
            else
            {
                high = mid1 - 1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{

    int n, m;
    cin >> n >> m;
    int arr[n];
    int brr[m];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    Solution obj;
    if (n < m)
        cout << obj.findMedian(arr, n, brr, m) << endl;
    else
        cout << obj.findMedian(brr, m, arr, n) << endl;

} // } Driver Code Ends