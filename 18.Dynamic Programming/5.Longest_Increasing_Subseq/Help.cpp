#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s2.size() < s1.size())
    {
        return false;
    }
    map<char, int> pat;
    map<char, int> str;
    for (int i = 0; i < s1.size(); ++i)
    {
        pat[s1[i]]++;
        str[s2[i]]++;
    }
    for (int i = s1.size(); i < s2.size(); ++i)
    {
        int count = 0;
        for (auto x : pat)
        {
            count += x.second;
            if (str.find(x.first) == str.end() || str[x.first] != x.second)
            {
                break;
            }
            else
            {
                if (count == s1.size())
                {
                    return true;
                }
            }
        }

        str[s2[i - s1.size()]]--;
        str[s2[i]]++;
    }
    int count = 0;
    for (auto x : pat)
    {
        count += x.second;
        if (str.find(x.first) == str.end() || str[x.first] != x.second)
        {
            break;
        }
        else
        {
            if (count == s1.size())
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s1 = "trinitrophenylmethylnitramine",
           s2 = "dinitrophenylhydrazinetrinitrophenylmethylnitramine";
    cout << checkInclusion(s1, s2) << "\n";
    return 0;
}