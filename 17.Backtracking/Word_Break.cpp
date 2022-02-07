#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void Word_Break(string ans, vector<string> dict, string str)
{
    if (str.length() == 0)
    {
        cout << "( " << ans << ")" << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string left = str.substr(0, i + 1);
        for (int j = 0; j < dict.size(); j++)
        {
            if (dict[j] == left)
            {
                string right = str.substr(i + 1);
                Word_Break(ans + left + ' ', dict, right);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> dict(n, "");
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    string str;
    cin >> str;
    Word_Break("", dict, str);
    return 0;
}
/*
i like sam sung samsung mobile ice
cream icecream man go mango
ilikeicecream
*/