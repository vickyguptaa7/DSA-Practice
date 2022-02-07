#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

void Largest_Number_Brute(string str, int k, string &ans)
{
    if (k == 0)
        return;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] < str[j])
            {
                swap(str[i], str[j]);
                if (str.compare(ans) > 0)
                    ans = str;
                Largest_Number_Brute(str, k - 1, ans);
                swap(str[i], str[j]);
            }
        }
    }
}

void Largest_Number_Optimal(int curri, string str, int k, string &ans)
{
    if (k == 0)
        return;
    char maxch = str[curri];
    for (int i = curri + 1; i < str.length(); i++)
    {
        if (maxch < str[i])
            maxch = str[i];
    }
    if (maxch != str[curri])
        k--;
    for (int i = str.length() - 1; i >=curri; i--)
    {
        if (maxch == str[i])
        {
            swap(str[curri], str[i]);
            if (str.compare(ans) > 0)
                ans = str;
            Largest_Number_Optimal(curri+1,str,k,ans);
            swap(str[curri],str[i]);
        }
    }
}

int main()
{
    int k;
    cin >> k;
    string str;
    cin >> str;
    string ans = str;
    Largest_Number_Optimal(0,str, k, ans);
    cout << ans;
    return 0;
}