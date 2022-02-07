#include <iostream>
using namespace std;

void Permutation_Case_Change(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    Permutation_Case_Change(str.substr(1), ans + str[0]);

    if (!isdigit(str[0]))
    {
        char ch = str[0];
        if (ch >= 65 && ch <= 90)
            ch = ch + 32;
        else
            ch = ch - 32;
        Permutation_Case_Change(str.substr(1), ans + ch);
    }
}

int main()
{
    string str;
    cin >> str;
    Permutation_Case_Change(str, "");
    return 0;
}