#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Number_Of_Triangle_In_Graph(vector<vector<int>> graph, int v)
{
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if (graph[i][j] && graph[j][k] && graph[k][i])
                {
                    count++;
                }
            }
        }
    }
    /* 
    if Graph Is Directed devide count by 6 
    Because A->B->C | B->C->A | C->A->B
     
    if Graph Is Undirected devide count by 6 
    Because A-B-C =>
    A->B->C | B->C->A | C->A->B
    B->A->C | A->C->A | C->B->A
    */
    return count/6;
}

int main()
{
    // Works For Both Directed And Undirected Graph
    int v = 4;
    vector<vector<int>>graph(v, vector<int>(v, 0));
    graph = {{0, 1, 1, 0},
             {1, 0, 1, 1},
             {1, 1, 0, 1},
             {0, 1, 1, 0}};
    cout << Number_Of_Triangle_In_Graph(graph, v)<<endl;
    return 0;
}