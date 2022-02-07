#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool mycomp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
    {
        if (a[2] == b[2])
            return a[0] < b[0];
        else
            return a[2] < b[2];
    }
    return a[1] < b[1];
}

class mycmp
{
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[2] > b[2];
    }
};

void Shortest_Job_First(vector<vector<int>> Process, int n)
{
    sort(Process.begin(), Process.end(), mycomp);
    vector<vector<int>> Schedule;
    priority_queue<vector<int>, vector<vector<int>>, mycmp> pq;
    pq.push(Process[0]);
    int timer = 0;
    int i = 1;
    while (!pq.empty())
    {
        vector<int> P = pq.top();
        pq.pop();
        timer += P[2];
        Schedule.push_back(P);
        while(true)
        {
            if(i<n&&Process[i][1]<=timer)
            {
                pq.push(Process[i]);
                i++;
            }
            else break;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Schedule[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Process(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        // Job_Id  Arrival_Time  Burst_Time
        for (int j = 0; j < 3; j++)
        {
            cin >> Process[i][j];
        }
    }
    Shortest_Job_First(Process, n);
    return 0;
}
/*
4
1 2 3
2 0 4
3 4 2
4 5 4
*/