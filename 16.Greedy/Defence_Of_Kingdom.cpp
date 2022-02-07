#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> x, y;
        x.push_back(0);
        y.push_back(0);
        for (int i = 0; i < k; i++)
        {
            int x_,y_;
            cin>>x_>>y_;
            x.push_back(x_);
            y.push_back(y_);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        x.push_back(n+1);
        y.push_back(m+1);
        int len=0,brdth=0;
        for(int i=1;i<x.size();i++)
        {
            len=max(len,x[i]-x[i-1]-1);
            brdth=max(brdth,y[i]-y[i-1]-1);
        }
        cout<<len*brdth<<endl;
    }

    return 0;
}