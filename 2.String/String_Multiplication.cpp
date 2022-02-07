#include <iostream>
#include <algorithm>
using namespace std;

string Add(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string ans;
    int len1 = s1.length(), len2 = s2.length();
    int carry = 0, i = 0;
    while (i < max(len1, len2))
    {
        int calc = carry;
        if (i < len1)
            calc += s1[i] - 48;
        if (i < len2)
            calc += s2[i] - 48;
        carry = 0;
        if (calc > 9)
        {
            carry = calc / 10;
        }
        ans += (calc % 10) + 48;
        i++;
    }
    if (carry == 1)
        ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiplyStrings(string s1, string s2)
{

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string ans2 = "0";
    int len1 = s1.length(), len2 = s2.length();
    for (int i = 0; i < len1; i++)
    {
        int carry = 0;
        string ans1;
        int n1 = s1[i] - 48;
        for (int j = 0; j < len2; j++)
        {
            int n2 = s2[j] - 48;
            int multi = n1 * n2 + carry;
            carry = 0;
            if (multi > 9)
            {
                carry = multi / 10;
            }
            ans1 += 48 + (multi % 10);
        }
        if (carry != 0)
        {
            while (carry > 0)
            {
                ans1 += 48 + (carry % 10);
                carry /= 10;
            }
        }
        for (int k = 0; k < i; k++)
            ans1+="0";
        ans2 = Add(ans1, ans2);
    }
    reverse(ans2.begin(), ans2.end());
    return ans2;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << multiplyStrings(s1, s2) << endl;
    return 0;
}