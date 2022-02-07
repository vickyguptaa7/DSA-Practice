#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

void Jobs_Sequencing(vector<pair<int, int>> Jobs, int n)
{
    sort(Jobs.begin(), Jobs.end(), mycomp);
    
    int Max_Time = 0;
    
    for (int i = 0; i < n; i++)
        Max_Time = max(Max_Time, Jobs[i].first);
    
    int slots[Max_Time];
    for(int i=0;i<Max_Time;i++)
    {
        slots[i]=-1;
    }
    
    int jcount = 0,jprice=0;
    for (int i = 0; i < n && jcount < Max_Time; i++)
    {
        for(int j=Jobs[i].first-1;j>=0;j--)
        {
            if(slots[j]==-1)
            {
                slots[j]=Jobs[i].first;
                jcount++;
                jprice+=Jobs[i].second;
                break;
            }
        }
    }
    for(int i=0;i<Max_Time;i++)
    {
        cout<<slots[i]<<" ";
    }
    cout<<endl<<jprice<<endl;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> Jobs;
    for (int i = 0; i < n; i++)
    {
        int j1, j2;
        cin >> j1 >> j2;
        Jobs.push_back({j1, j2});
    }
    Jobs_Sequencing(Jobs,n);
    return 0;
}
/*
5
1 50
2 10
1 20
3 30
2 100

4
4 70
1 80
1 30
1 100

4
2 50
2 60
3 20 
3 30

*/