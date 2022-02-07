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

string Postfix_Infix(string str, int n)
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
            string op1=st.top(); st.pop();
            string op2=st.top(); st.pop();
            ans="("+op2+str[i]+op1+")";
            st.push(ans);
        }
    }

    return st.top();
}

int main()      
{
    string str;
    cin >> str;
    int n = str.length();

    cout << Postfix_Infix(str, n) << endl;
    return 0;
}