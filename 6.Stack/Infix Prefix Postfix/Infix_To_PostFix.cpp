#include <iostream>
using namespace std;
struct stack
{
    char *arr;
    int top;
    stack()
    {
        arr = new char[100];
        top = -1;
    }
    void push(char data)
    {
        if (top == 100 - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    char Top()
    {
        if (top == -1)
        {
            cout << "Empty" << endl;
            return '!';
        }
        return arr[top];
    }
    bool empty()
    {
        return (top == -1) ? 1 : 0;
    }
};

int Precedence(char ch)
{
    switch (ch)
    {
    case '(':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        return 0;
    }
}

string Infix_To_Prefix(string str, int n)
{
    stack st;
    string ans;
    for (int i = 0; i < n; i++)
    {
        if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            ans += str[i];
        }
        else if (str[i] == '(' || str[i] == ')')
        {
            if (str[i] == '(')
                st.push(str[i]);
            else
            {
                while (st.Top() != '(' && !st.empty())
                {
                    ans += st.Top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
        }
        else
        {
            if (st.empty())
                st.push(str[i]);
            else if (Precedence(st.Top()) < Precedence(str[i]))
                st.push(str[i]);
            else if (!st.empty() && Precedence(st.Top()) > Precedence(str[i]))
            {
                while (!st.empty() && Precedence(st.Top()) > Precedence(str[i]))
                {
                    ans += st.Top();
                    st.pop();
                }
                st.push(str[i]);
            }
            else
            {
                if (Precedence(st.Top()) == Precedence(str[i]) && str[i] == '^')
                {
                    st.push(str[i]);
                }
                else
                {
                    while (!st.empty() && Precedence(st.Top()) >= Precedence(str[i]))
                    {
                        ans += st.Top();
                        st.pop();
                    }
                    st.push(str[i]);
                }
            }
        }
    }
    while (!st.empty())
    {
        ans += st.Top();
        st.pop();
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    cout << Infix_To_Prefix(str, n) << endl;

    return 0;
}
