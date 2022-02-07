#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(vector<int>a,vector<int>b)
{
    return a[1]<b[1];
}

int Maximum_Stoppage(vector<vector<int>> Timings, int n)
{
    int stations = 0;
    for (int i = 0; i < n; i++)
            stations = max(stations,Timings[i][2]);

    vector<int>stn(stations,-1);
    sort(Timings.begin(),Timings.end(),mycomp);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(stn[Timings[i][2]-1]==-1||Timings[i][0]>Timings[stn[Timings[i][2]-1]][1])
        {
            stn[Timings[i][2]-1]=i;
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Timing;
    for (int i = 0; i < n; i++)
    {
        vector<int> rows(3);
        for (int i = 0; i < 3; i++)
            cin >> rows[i];
        Timing.push_back(rows);
    }
    cout << Maximum_Stoppage(Timing, n) << endl;
    return 0;
}
/*
6
1000 1030 1
1010 1030 1
1000 1020 2
1030 1230 2
1200 1230 3
0900 1005 1

3
1000 1030 1
1110 1130 1
1200 1220 1

5
1000 1030 1
1010 1020 1
1025 1040 1
1130 1145 2
1130 1140 2
*/