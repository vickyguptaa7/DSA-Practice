#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max_Equal_Sum(vector<int> s1, vector<int> s2, vector<int> s3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (auto x : s1)
        sum1 += x;
    for (auto x : s2)
        sum2 += x;
    for (auto x : s3)
        sum3 += x;
    while (!s1.empty() && !s2.empty() && !s3.empty())
    {
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
        else if (sum1>=sum2&&sum1>=sum3)
        {
            sum1-=*s1.rbegin();
            s1.pop_back();
        }
        else if(sum2>=sum1&&sum2>=sum3)
        {
            sum2-=*s2.rbegin();
            s2.pop_back();
        }
        else if(sum3>=sum1&&sum3>=sum2)
        {
            sum3-=*s3.rbegin();
            s3.pop_back();
        }
    }
    return 0;
}

int main()
{
    int p, q, r;
    cin >> p >> q >> r;
    vector<int> s1(p), s2(q), s3(r);
    for (int i = 0; i < p; i++)
        cin >> s1[i];
    for (int i = 0; i < q; i++)
        cin >> s2[i];
    for (int i = 0; i < r; i++)
        cin >> s3[i];

    cout << Max_Equal_Sum(s1, s2, s3) << endl;
    return 0;
}