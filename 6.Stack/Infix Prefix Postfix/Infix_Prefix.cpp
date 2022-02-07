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

string string_reverse(string str)
{
    int n = str.length();
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        char ch = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = ch;
    }
    return str;
}

void push_at_bottom(stack st, char ch)
{
    if (st.empty())
    {
        st.push(ch);
        return;
    }
    char a = st.Top();
    st.pop();
    push_at_bottom(st, ch);
    st.push(a);
}

void stack_reverse(stack st)
{
    if (st.empty())
        return;
    char val = st.Top();
    st.pop();
    push_at_bottom(st, val);
}

string Correct_Bracket(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
    return str;
}

string Infix_To_Prefix(string str, int n)
{
    str = string_reverse(str);
    str = Correct_Bracket(str, n);
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
            else if(!st.empty() && Precedence(st.Top()) > Precedence(str[i]))
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
                if(Precedence(st.Top()) == Precedence(str[i])&&str[i]=='^')
                {
                    while((!st.empty()) &&(Precedence(st.Top()) >= Precedence(str[i]))&&(str[i]=='^'))
                    {
                        ans += st.Top();
                        st.pop();
                    }
                    st.push(str[i]);
                }
                else
                {
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
    return string_reverse(ans);
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    cout << Infix_To_Prefix(str, n) << endl;

    return 0;
}