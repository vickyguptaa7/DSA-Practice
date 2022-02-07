#include <iostream>
using namespace std;

int *longest_P_S(string str, int n)
{
    int *lps = new int[n];
    lps[0] = 0;
    int i = 0, j = 1;

    while (j < n)
    {
        if (str[i] == str[j])
        {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = lps[i - 1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }
    return lps;
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int *LPS = longest_P_S(str, len);

    string txt = "abcabcabc";
    int tlen = txt.length();
    int i = 0, j = 0;
    while (j < tlen)
    {
        if (txt[j] == str[i])
        {
            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = LPS[i];
            }
            else
            {
                j++;
            }
        }
        if (i == len)
        {
            cout << j - i << endl;
        }
    }
    for (int i = 0; i < 3; i++)
        cout << LPS[i] << " ";
    cout << endl;
    return 0;
}