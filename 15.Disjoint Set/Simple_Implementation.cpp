#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

class DisjSet
{
    int *parent;
    int size;

public:
    DisjSet(int capacity)
    {
        size = capacity;
        parent = new int[size];
        initializer();
    }
    void initializer()
    {
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return Find(parent[x]);
    }
    void Union(int x, int y)
    {
        int x_rep = Find(x);
        int y_rep = Find(y);

        if (x_rep == y_rep)
            return;
        parent[y_rep] = x_rep;
    }
};

int main()
{
    DisjSet Facebook(5);
    cout << Facebook.Find(0) << " " << Facebook.Find(1) << endl;
    Facebook.Union(0, 1);
    cout << Facebook.Find(0) << " " << Facebook.Find(1) << endl;
    Facebook.Union(2, 3);
    cout << Facebook.Find(2) << " " << Facebook.Find(3) << endl;
    Facebook.Union(3, 0);
    cout << Facebook.Find(0) << " " << Facebook.Find(3) << endl;
    return 0;
}