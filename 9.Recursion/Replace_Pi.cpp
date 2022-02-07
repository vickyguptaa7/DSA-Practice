#include <iostream>
using namespace std;

string Replace(string str, int i = 0)
{
    if (i + 1 == str.length())
    {
        return str;
    }
    if (str[i] == 'p' && str[i + 1] == 'i')
    {
        str.erase(i, 2);
        str.insert(i, "3.14");
        return Replace(str, i + 3);
    }
    return Replace(str, i + 1);
}
#include <cstring>

string helper(string s, int i)
{

    if (i + 1 == s.length())
    {
        return s;
    }

    if (s[i] == 'p' && s[i + 1] == 'i')
    {
        s.erase(i, 2);
        s.insert(i, "3.14");
        return helper(s, i + 3);
    }

    return helper(s, i + 1);
}

void replacePi(char input[])
{
    // Write your code here

    int len = strlen(input);

    string s;
    for (int i = 0; i < len; i++)
    {
        s += input[i];
    }

    string ans = helper(s, 0);

    for (int i = 0; i < ans.length(); i++)
    {
        input[i] = ans[i];
    }

    input[ans.length()] = '\0';
}
int main()
{
    char ch[1000] = "xpix";
    replacePi(ch);
    cout << ch << endl;
    return 0;
}