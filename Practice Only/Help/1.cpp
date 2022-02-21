#include <bits/stdc++.h>
using namespace std;
void radix(vector<int> &v)
{
    cout << "flag\n";
    vector<vector<int>> temp(10);
    // int i=0;
    int divisor = 1;
    while (temp[0].size() != v.size())
    {
        for (int i = 0; i < temp.size(); i++)
            temp[i].clear();
        int j;
        for (auto i : v)
        {
            j = i;
            j = j / divisor;
            j = j % (divisor * 10);
            temp[j].push_back(i);
        }
        divisor *= 10;
        j = 0;
        for (auto &i : temp)
        {
            for (auto &k : i)
                v[j++] = k;
        }
    }
}
int main()
{
    cout << "Give the size of the array" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    cout << "Give the array" << endl;
    // for(auto &i:v){
    //     cin>>i;
    //     // cout<<"flag1\n";
    // }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    radix(v);
    for (auto &i : v)
        cout << i << " ";
    return 0;
}