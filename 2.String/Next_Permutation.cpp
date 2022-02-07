#include <iostream>
#include <string>
using namespace std;

string Swap(string str, int i, int j)
{
    char ch = str[i];
    str[i] = str[j];
    str[j] = ch;
    return str;
}

string Reverse(string str, int s)
{
    int len = str.length();
    int l = len - 1;
    while (s < l)
    {
        str = Swap(str, l, s);
        l--;
        s++;
    }
    return str;
}

string Next_Permutation(string str)
{
    int len = str.length();
    if (len <= 1)
        return "-1";
    int index = 0;
    int i;
    for (i = len - 2; i >= 0; i--)
    {
        if (str[i] < str[i +1])
        {
            index = i ;
            break;
        }
    }
    if (i >=0)
    {
        int idx;
        for (int i = len - 1; i > index; i--)
        {
            if (str[index] < str[i])
            {
                idx = i;
                break;
            }
        }
        str = Swap(str, idx, index);
        str = Reverse(str, index + 1);
    }
    else
    {
        str = Reverse(str, index);
    }

    
    return str;
}

int main()
{
    string str;
    cin >> str;

    cout << Next_Permutation(str) << endl;

    return 0;
}