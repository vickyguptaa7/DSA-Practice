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