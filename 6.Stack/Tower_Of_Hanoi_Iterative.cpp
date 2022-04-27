#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

bool Move_Disc(stack<int> &st1, stack<int> &st2)
{
    bool chk; // check from which tower the disc move to which str1->str2 true str2->str1 false
    if (st1.empty() || st2.empty())
    {
        if (st2.empty())
        {
            st2.push(st1.top());
            st1.pop();
            chk = true;
        }
        else
        {
            st1.push(st2.top());
            st2.pop();
            chk = false;
        }
    }
    else if (st1.top() > st2.top())
    {
        st1.push(st2.top());
        st2.pop();
        chk = false;
    }
    else
    {
        st2.push(st1.top());
        st1.pop();
        chk = true;
    }
    return chk;
}

void showMove(bool chk, char a, char b)
{
    (chk) ? cout << "The Move Is From " << a << " -> " << b << endl : cout << "The Move Is From " << b << " -> " << a << endl;
}

void Tower_Of_Hanoi(stack<int> &S, stack<int> &H, stack<int> &D, int n)
{
    long long int steps = pow(2, n) - 1;
    char s = 'S', h = 'H', d = 'D';
    if (n % 2 == 0)
    {
        h = 'D';
        d = 'H';
    }

    for (long long int i = 1; i <= steps; i++)
    {
        if (i % 3 == 0)
        {
            bool chk = Move_Disc(H, D);
            showMove(chk, h, d);
        }
        else if (i % 3 == 1)
        {
            bool chk = Move_Disc(S, D);
            showMove(chk, s, d);
        }
        else
        {
            bool chk = Move_Disc(S, H);
            showMove(chk, s, h);
        }
    }
}

int main()
{
    int n;
    cout << "No Of Disc : ";
    cin >> n;
    stack<int> source, helper, destination;
    for (int i = n; i >= 1; i--)
        source.push(i);

    Tower_Of_Hanoi(source, helper, destination, n);

    return 0;
}