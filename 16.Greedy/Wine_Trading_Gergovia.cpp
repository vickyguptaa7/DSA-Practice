#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long Trading_Wine_Without_Space(int arr[], int n)
{
    long long cost = 0;
    for (int i = 1; i < n; i++)
    {
        cost += abs(arr[i - 1]);
        arr[i] += arr[i - 1];
    }
    return cost;
}

long long Trading_Wine_Space(int arr[], int n)
{
    vector<pair<int, int>> Buy, Sell;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            Buy.push_back({arr[i], i});
        else
            Sell.push_back({arr[i], i});
    }
    int i=0,j=0,cost=0;
    while(i<Buy.size()&&j<Sell.size())
    {
        int purchase=min(Buy[i].first,-Sell[j].first);
        int diff=abs(Buy[i].second-Sell[j].second);
        cost+=purchase*diff;
        Buy[i].first-=purchase;
        Sell[j].first+=purchase;
        if(Buy[i].first==0)i++;
        if(Sell[j].first==0)j++;
    }
    return cost;
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

    cout << Trading_Wine_Space(arr, n) << endl;

    return 0;
}