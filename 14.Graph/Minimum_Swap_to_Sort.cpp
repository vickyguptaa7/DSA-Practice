#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void cycleLen(vector<pair<int, int>> &sarr, vector<int> &isVisited, int src, int &len)
{
    if (isVisited[src])
        return;
    isVisited[src] = 1;
    len++;
    cycleLen(sarr, isVisited, sarr[src].second, len);
}

int minSwaps(vector<int> &nums)
{
    vector<pair<int, int>> sarr(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        sarr[i] = {nums[i], i};
    }
    sort(sarr.begin(), sarr.end());
    vector<int> isVisited(nums.size(), 0);
    int swapCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (isVisited[i] == 0)
        {
            int len = 0;
            cycleLen(sarr, isVisited, i, len);
            swapCount += len - 1;
        }
    }
    return swapCount;
}

int main()
{

    return 0;
}