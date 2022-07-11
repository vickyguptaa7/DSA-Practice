#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

class DisjSet
{
    int *parent;
    int *rank;
    int size;

public:
    DisjSet(int capacity)
    {
        size = capacity;
        parent = new int[size];
        rank = new int[size];
        initializer();
    }
    void initializer()
    {
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        parent[x]=Find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int x_rep = Find(x);
        int y_rep = Find(y);

        if (x_rep == y_rep)
            return;
        if (rank[x_rep] > rank[y_rep])
            parent[y_rep] = x_rep;
        else if (rank[y_rep] > rank[x_rep])
            parent[x_rep] = y_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
}; 

int main()
{
    DisjSet Facebook(5);

    cout << Facebook.Find(3) << " " << Facebook.Find(4) << endl;
    Facebook.Union(3, 4);
    cout << Facebook.Find(3) << " " << Facebook.Find(4) << endl;

    cout << Facebook.Find(3) << " " << Facebook.Find(2) << endl;
    Facebook.Union(3, 2);
    cout << Facebook.Find(3) << " " << Facebook.Find(2) << endl;

    cout << Facebook.Find(2) << " " << Facebook.Find(1) << endl;
    Facebook.Union(1, 2);
    cout << Facebook.Find(1) << " " << Facebook.Find(2) << endl;

    cout << Facebook.Find(0) << " " << Facebook.Find(1) << endl;
    Facebook.Union(0, 1);
    cout << Facebook.Find(0) << " " << Facebook.Find(1) << endl;

    return 0;
}