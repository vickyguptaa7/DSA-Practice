#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool DFS(int x, int y, string str, int ind, vector<vector<char>> board, vector<vector<bool>> &isVisited)
{
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || isVisited[x][y] == 1 || board[x][y] != str[ind])
        return false;
    if (ind == str.length() - 1)
        return true;
    int dx[8] = {0, 1, -1, 0, 1, -1, -1, 1};
    int dy[8] = {1, 0, 0, -1, 1, -1, 1, -1};
    isVisited[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (DFS(nx, ny, str, ind + 1, board, isVisited))
            return true;
    }
    return false;
}

void Word_Boggle(int n, vector<string> dictionary, int p, int q, vector<vector<char>> board)
{

    vector<string> answer;
    map<char, vector<pair<int, int>>> Map;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            Map[board[i][j]].push_back({i, j});
        }
    }
    for (int i = 0; i < n; i++)
    {
        string str = dictionary[i];
        vector<vector<bool>> isVisited(p, vector<bool>(q, 0));
        for (auto x : Map[str[0]])
        {
            if (DFS(x.first, x.second, str, 0, board, isVisited))
            {
                answer.push_back(dictionary[i]);
                break;
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    fflush(stdin);
    vector<string> dictionary;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        dictionary.push_back(str);
    }
    int p, q;
    cin >> p >> q;
    fflush(stdin);
    vector<vector<char>> board(p, vector<char>(q));
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> board[i][j];
        }
    }
    Word_Boggle(n, dictionary, p, q, board);
    return 0;
}
/*
1
CAT
3 3
C A P
A N D
T I E

4
GEEKS
FOR
QUIZ
GO
3 3
G I Z
U E K
Q S E
*/