#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string Bracket_Reversal(string str)
{
    int n = str.length();
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            st.push("(");
        else if (str[i] >= 'a' && str[i] <= 'z')
            st.push(str.substr(i, 1));
        else
        {
            string ans = "";
            while (!st.empty() && st.top() != "(")
            {
                reverse(st.top().begin(),st.top().end());
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
            st.push(ans);
        }
    }
    
    if (st.size() > 1)
    {
        string ans;
        while (!st.empty())
        {
            reverse(st.top().begin(),st.top().end());
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    return st.top();
}

int main()
{
    string str;
    cin >> str;
    cout << Bracket_Reversal(str) << endl;
    return 0;
}