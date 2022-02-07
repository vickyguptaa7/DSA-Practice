#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int strt, fnsh, profit;
};

bool mycomp(Job a, Job b)
{
    if (a.strt != b.strt)
    {
        return a.strt < b.strt;
    }
    else
    {
        return a.fnsh < b.fnsh;
    }
}

int Job_Scheduling_Max_Profit(int n, int prev, Job job[], vector<vector<int>> &dp)
{
    if (n <= 0)
        return 0;
    if (prev != -1 && dp[n][prev + 1] != -1)
        return dp[n][prev + 1];
    if (prev == -1 || job[prev].strt >= job[n - 1].fnsh)
    {
        dp[n][prev + 1] = max(Job_Scheduling_Max_Profit(n - 1, prev, job, dp), job[n - 1].profit + Job_Scheduling_Max_Profit(n - 1, n - 1, job, dp));
    }
    else
    {
        dp[n][prev + 1] = Job_Scheduling_Max_Profit(n - 1, prev, job, dp);
    }
    return dp[n][prev + 1];
}

int Job_Scheduling_Max_Profit_Tabu(int n, Job job[])
{
    vector<int> dp(n, 0);
    dp[0] = job[0].profit;
    int answer = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = job[i].profit;
        for (int j = 0; j < i; j++)
        {
            if (job[i].strt >= job[j].fnsh)
            {
                dp[i] = max(dp[i], job[i].profit + dp[j]);
            }
        }
        answer = max(answer, dp[i]);
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;
    Job job[n];
    for (int i = 0; i < n; i++)
    {
        cin >> job[i].strt >> job[i].fnsh >> job[i].profit;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    sort(job, job + n, mycomp);
    cout << Job_Scheduling_Max_Profit(n, -1, job, dp) << "\n";
    cout << Job_Scheduling_Max_Profit_Tabu(n, job) << "\n";
    return 0;
}
/*
4
1 2 50
3 5 20
6 19 100
2 100 200
*/