#include <iostream>
#include <stack>

using namespace std;

string Reverse(string str)
{
    int n=str.length();
    for(int i=0;i<(n+1)/2;i++)
    {
        char ch=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=ch;
    }
    return str;
}

string Postfix_Prefix(string str, int n)
{
    stack<string> st;

    for(int i=0;i<n;i++)
    {
        if((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            st.push(string(1,str[i]));
        }
        else 
        {
            string ans;
            ans+=st.top(); st.pop();
            ans+=st.top(); st.pop();
            ans+=str[i];
            st.push(ans);
        }
    }

    return Reverse(st.top());
}

int main()      
{
    string str;
    cin >> str;
    int n = str.length();

    cout << Postfix_Prefix(str, n) << endl;
    return 0;
}