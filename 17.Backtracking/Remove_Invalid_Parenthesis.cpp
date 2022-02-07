#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

int Min_Bracket_Removal(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '(' && str[i] != ')')
            continue;
        if (!st.empty() && st.top() == '(' && str[i] == ')')
        {
            st.pop();
        }
        else
            st.push(str[i]);
    }
    return st.size();
}

void Remove_Invalid_Parenthesis_Brute(int min_bracket, string str, set<string> &oset)
{
    if (min_bracket == 0)
    {
        if (Min_Bracket_Removal(str) == 0)
        {
            if (oset.find(str) == oset.end())
                oset.insert(str);
        }
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')' || str[i] == '(')
        {
            Remove_Invalid_Parenthesis_Brute(min_bracket - 1, str.substr(0, i) + str.substr(i + 1), oset);
        }
    }
}

void Remove_Valid_Parentheses_Opt(int min_bracket, string str, unordered_set<string> &uset, vector<string> &res)
{
    if (uset.find(str) != uset.end())
        return;
    uset.insert(str);
    if (min_bracket == 0)
    {
        if (Min_Bracket_Removal(str) == 0)
            res.push_back(str);
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')' || str[i] == '(')
        {
            Remove_Valid_Parentheses_Opt(min_bracket - 1, str.substr(0, i) + str.substr(i + 1),uset,res);
        }
    }
}

int main()
{
    string str;
    cin >> str;
    int min_bracket = Min_Bracket_Removal(str);
    cout << min_bracket << endl;
    set<string> oset;
    unordered_set<string> uset;
    vector<string>res;
    Remove_Valid_Parentheses_Opt(min_bracket, str, uset,res);
    for (auto x : res)
    {
        cout << x << endl;
    }
    return 0;
}