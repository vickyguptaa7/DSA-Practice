#include <iostream>
using namespace std;
int Parentheses_Score(string s)
{
    static int i=0;
    int score = 0;
    while (i < s.length())
    {
        char fch = s[i];
        i++;
        if (fch == '(')
        {
            if (s[i] == ')')
            {
                score++;
                i++;
            }
            else
            {
                score+=2*Parentheses_Score(s);
            }
        }
        else
        {
            return score;
        }
    }
    i=0;
    return score;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << Parentheses_Score(s) <<endl;
    }
    return 0;
}