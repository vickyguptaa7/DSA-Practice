#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int p, q = 0;
    cin >> p;
    while (p > q)
    {
        int n, k, b, t;
        cin >> n >> k >> b >> t;
        int x[n], v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int not_possible = 0, swap = 0, count = 0;
        for (int i = n-1; i >=0; i--)
        {
            int to_travel = b - x[i];
            int travel = v[i] * t;
            if (travel >= to_travel)
            {
                count++;

                swap += not_possible;
            }
            else
            {
                not_possible++;
            }
            if(count>=k)break;
        }
        if(count>=k)
        {
            cout<<"Case #"<<++q<<": "<<swap<<endl;
        }
        else
        {
            cout<<"Case #"<<++q<<": IMPOSSIBLE"<<endl;
        }
    }   
    return 0;
}