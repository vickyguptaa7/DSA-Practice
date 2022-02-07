#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Median
{
    public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    void balanceHeaps()
    {
        if (right.size() - left.size() == 2)
        {
            left.push(right.top());
            right.pop();
        }
        else if (left.size() - right.size() == 2)
        {
            right.push(left.top());
            left.pop();
        }
    }

    void insertHeap(int &x)
    {
        if (right.size() && right.top() <= x)
        {
            right.push(x);
        }
        else
        {
            left.push(x);
        }
        balanceHeaps();
    }

    double getMedian()
    {
        if (right.size() == left.size())
            return (double(left.top()) + right.top()) / 2;

        else if (right.size() > left.size())
            return right.top();
        else
            return left.top();
    }
};

int main()
{

    int n, x;
    Median object;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        object.insertHeap(x);
        cout << object.getMedian() << endl;
    }

    return 0;
}