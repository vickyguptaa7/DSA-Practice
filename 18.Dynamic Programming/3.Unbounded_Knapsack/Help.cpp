#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &piles, int mid, int h)
{
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        int time = ceil(piles[i] / (double)mid);
        h -= time;
        if (h < 0)
            return 0;
    }
    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int low = 0, high = *max_element(piles.begin(), piles.end());
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(piles, mid, h))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> banana = {1000000000};
    int h = 2;
    cout << minEatingSpeed(banana, h) << "\n";
    return 0;
}