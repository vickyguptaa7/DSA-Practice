#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

void Water_Jug_BFS(int jug1, int jug2, int target)
{
    if (jug1 + jug2 < target)
    {
        cout << "Not Possible" << endl;
    }
    set<pi> isVisited;
    queue<pi> que;
    isVisited.insert({0, 0});
    que.push({0, 0});
    int steps=-1;// One Extra Steps Is counted
    bool Found=false;
    while (que.empty()==false&&Found==false)
    {
        int size = que.size();
        while (size--)
        {
            int j1 = que.front().first;
            int j2 = que.front().second;
            que.pop();
            if (j1 + j2 == target || j1 == target || j2 == target)
            {
                Found=true;
                break;
            }
            int newJ1, newJ2;
            pair<int, int> newJug;
            // j1->j2
            newJ1 = j1 - min(j1, jug2 - j2);
            newJ2 = j2 + min(j1, jug2 - j2);
            newJug = {newJ1, newJ2};
            if (isVisited.find(newJug) == isVisited.end())
            {
                isVisited.insert(newJug);
                que.push(newJug);
            }

            // j2->j1
            newJ2 = j2 - min(j2, jug1 - j1);
            newJ1 = j1 + min(j2, jug1 - j1);
            newJug = {newJ1, newJ2};
            if (isVisited.find(newJug) == isVisited.end())
            {
                isVisited.insert(newJug);
                que.push(newJug);
            }

            // Empty Jug 1 Completely
            newJ1 = 0;
            newJ2 = j2;
            newJug = {newJ1, newJ2};
            if (isVisited.find(newJug) == isVisited.end())
            {
                isVisited.insert(newJug);
                que.push(newJug);
            }

            // Empty Jug 2 Completely
            newJ1 = j1;
            newJ2 = 0;
            newJug = {newJ1, newJ2};
            if (isVisited.find(newJug) == isVisited.end())
            {
                isVisited.insert(newJug);
                que.push(newJug);
            }

            // Fill Jug 1 Completely
            newJ1 = jug1;
            newJ2 = j2;
            newJug = {newJ1, newJ2};
            if (isVisited.find(newJug) == isVisited.end())
            {
                isVisited.insert(newJug);
                que.push(newJug);
            }

            // Fill Jug 2 Completely
            newJ1 = j1;
            newJ2 = jug2;
            newJug = {newJ1, newJ2};
            if (isVisited.find(newJug) == isVisited.end())
            {
                isVisited.insert(newJug);
                que.push(newJug);
            }
        }
        steps++;
    }
    if(Found)
    {
        cout<<"Found"<<endl;
        cout<<"Steps : "<<steps<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    
}

int main()
{
    int jug1, jug2, target;
    cin >> jug1 >> jug2 >> target;
    Water_Jug_BFS(jug1, jug2, target);
    return 0;
}