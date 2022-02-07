#include <iostream>
#include <queue>
using namespace std;

void Reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int val = q.front();
    q.pop();
    Reverse(q);
    q.push(val);
}

void Reverse_k(queue<int> &q, int n, int k)
{
    if (q.size() == n - (k))
    {
        return;
    }
    int val = q.front();
    q.pop();
    Reverse_k(q, n, k);
    q.push(val);
}

queue<int> Reverse_First_k(queue<int> q, int k)
{
    queue<int> Aux;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        Aux.push(q.front());
        q.pop();
        if (i == k - 1)
        {
            Reverse(Aux);
        }
    }
    return Aux;
}

void Display(queue<int> q, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    Display(q, q.size());

    Display(Reverse_First_k(q, 3), q.size());

    return 0;
}