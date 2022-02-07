#include <iostream>
#include <stack>

using namespace std;

string Prefix_Postfix(string str, int n)
{
    stack<string> st;

    for(int i=n-1;i>=0;i--)
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

    return st.top();
}

int main()      
{
    string str;
    cin >> str;
    int n = str.length();

    cout << Prefix_Postfix(str, n) << endl;
    return 0;
}