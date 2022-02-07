#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{

    unordered_map<int, int> snake, ladder;
    int snk, ldr;
    cin >> snk;
    for (int i = 0; i < snk; i++)
    {
        int from, to;
        cin >> from >> to;
        snake[from] = to;
    }
    cin >> ldr;
    for (int i = 0; i < ldr; i++)
    {
        int from, to;
        cin >> from >> to;
        ladder[from] = to;
    }
    int isVisited[101] = {0};
    queue<int> que;
    que.push(1);
    isVisited[1] = 1;
    bool found=false;
    int moves = 0;
    while (que.size()&&!found)
    {
        int size = que.size();
        while (size--)
        {
            int node = que.front();
            que.pop();
            for (int i = 1; i <= 6; i++)
            {
                if (node + i == 100)
                {
                    found=true;
                }
                if (node + i <= 100 && isVisited[node + i] == false)
                {
                    if (snake.find(node + i) != snake.end() && isVisited[snake[node + i]]==0)
                    {
                        isVisited[snake[node + i]] = 1;
                        que.push(snake[node + i]);
                    }
                    else if (ladder.find(node + i) != ladder.end() && isVisited[ladder[node + i]]==0)
                    {
                        isVisited[ladder[node + i]] = 1;
                        if (ladder[node + i] == 100)
                        {
                            found=true;
                        }
                        que.push(ladder[node + i]);
                    }
                    else if (ladder.find(node + i) == ladder.end() && snake.find(node + i) == snake.end())
                    {
                        isVisited[node + i] = true;
                        que.push(node + i);
                    }
                }
            }
        }
        moves++;
    }
    if(found)
    {
        cout<<moves<<endl;
    }
    else 
    {
        cout<<"Not Found"<<endl;
    }
    return 0;
}
/*
3
99 10
30 20
20 5
2
3 90
56 76
*/