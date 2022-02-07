#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Min_Cost_To_Cut_Board(vector<int> horiz_cut, vector<int> verti_cut, int n, int m)
{
    int h_piece = 1, v_piece = 1;
    sort(horiz_cut.begin(), horiz_cut.end(), greater<int>());
    sort(verti_cut.begin(), verti_cut.end(), greater<int>());
    int i = 0, j = 0, total_cost = 0;
    while (i < n && j < m)
    {
        if (horiz_cut[i] >= verti_cut[j])
        {
            total_cost += horiz_cut[i] * v_piece;
            h_piece++;
            i++;
        }
        else
        {
            total_cost += verti_cut[j] * h_piece;
            v_piece++;
            j++;
        }
    }
    while (i < n)
    {
        total_cost += horiz_cut[i] * v_piece;
        h_piece++;
        i++;
    }
    while (j < m)
    {
        total_cost += verti_cut[j] * h_piece;
        v_piece++;
        j++;
    }
    return total_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    n--,m--;
    vector<int> horiz_cut(n), verti_cut(m);
    for (int i = 0; i < n; i++)
        cin >> horiz_cut[i];
    for (int i = 0; i < m; i++)
        cin >> verti_cut[i];
    cout << Min_Cost_To_Cut_Board(horiz_cut,verti_cut,n,m)<<endl;
    return 0;
}
/*
4 14
4 1 2 5
2 1 3 1 4 11 2 4 5 6 7 8 9
*/