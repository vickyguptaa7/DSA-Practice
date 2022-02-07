#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void Add_Adjacent(vector<pair<int, int>> list[], int v, int u, int w)
{
    list[v].push_back({u, w});
}

void Print_Graph(vector<pair<int, int>> list[], int v)
{
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto x : list[i])
        {
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void Print_Matrix(vector<vector<int>>matrix)
{
    int v=matrix.size();
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void FW_APSP(vector<pair<int, int>> list[], int v)
{
    vector<vector<int>> matrix(v, vector<int>(v, 1e1));
    for (int i = 0; i < v; i++)
        matrix[i][i] = 0;
    for (int i = 0; i < v; i++)
    {
        for (auto x : list[i])
        {
            matrix[i][x.first] = x.second;
        }
    }


    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if(matrix[i][j]>matrix[i][k]+matrix[k][j])
                {
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                }
            }
        }
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if(matrix[i][j]>matrix[i][k]+matrix[k][j])
                {
                    cout<<"Negative Weight Cycle Is Present"<<endl;
                    return;
                }
            }
        }
    }
    Print_Matrix(matrix);
}



int main()
{
    int v = 4;
    vector<pair<int, int>> list[v];
    // Add_Adjacent(list, 1, 4, 40);
    // Add_Adjacent(list, 1, 2, 10);
    // Add_Adjacent(list, 2, 3, 10);
    // Add_Adjacent(list, 3, 4, 10);
    // Add_Adjacent(list, 3, 5, 2);
    // Add_Adjacent(list, 5, 6, 3);
    // Add_Adjacent(list, 6, 7, 3);
    // Add_Adjacent(list, 5, 7, 8);
    Add_Adjacent(list, 0, 1, 2);
    Add_Adjacent(list, 1, 2, 1);
    Add_Adjacent(list, 2, 0, 3);
    Add_Adjacent(list, 2, 3, 4);
    // Add_Adjacent(list,2,5,5);
    // Add_Adjacent(list,3,5,1);
    Print_Graph(list, v);
    
    FW_APSP(list, v);
    return 0;
}