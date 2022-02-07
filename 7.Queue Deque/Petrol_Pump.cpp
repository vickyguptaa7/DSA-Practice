#include <iostream>
#include <queue>

using namespace std;

int First_Petrol_Pump_Brute(int pet[], int dest[], int n)
{
    int psum = 0, dsum = 0;
    for (int i = 0; i < n; i++)
    {
        psum = 0;
        dsum = 0;
        bool chk = true;
        for (int j = i; j < n; j++)
        {
            psum += pet[j];
            dsum += dest[j];
            if (dsum > psum)
            {
                chk = false;
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            psum += pet[j];
            dsum += dest[j];
            if (dsum > psum)
            {
                chk = false;
                break;
            }
        }
        if (chk)
            return i + 1;
    }
    return -1;
}

int First_Petrol_Pump_Better(int pet[], int dest[], int n)
{

    int csum = 0;
    for (int i = 0; i < n; i++)
    {
        csum += pet[i] - dest[i];
    }

    if (csum < 0)
        return -1;
    queue<int> q;
    int currsum = 0;
    int i = 0;
    while (q.size() != n)
    {
        q.push(i);
        currsum += pet[i] - dest[i];
        while (!q.empty() && currsum < 0)
        {
            currsum -= pet[q.front()] - dest[q.front()];
            q.pop();
        }

        i = (i + 1) % n;
    }
    return q.front() + 1;
}

int First_Petrol_Pump_Optimal(int pet[], int dest[], int n)
{
    // int csum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     csum += pet[i] - dest[i];
    // }

    // if (csum < 0)
    //     return -1;

    int ans = 0,psum=0; // psum keep the records when pet-dest is negative so that in last we can assure 
    int csum = pet[0] - dest[0]; // that we have chose the correct petrol pump
    for (int i = 1; i < n; i++)
    {
        if (csum < 0)
        {
            psum+=csum;
            ans = i;
            csum = 0;
        }
        csum +=  pet[i] - dest[i];
    }
    return (csum+psum>=0)?ans:-1;
}

int main()
{
    int n;
    cin >> n;
    int pet[n], dest[n];

    for (int i = 0; i < n; i++)
        cin >> pet[i];
    for (int i = 0; i < n; i++)
        cin >> dest[i];

    cout << First_Petrol_Pump_Brute(pet, dest, n) << endl;

    return 0;
}
// 32
// 98 18 82 72 10 76 68 28 98 57 87 54 7 66 20 84 29 25 33 72 4 30 71 20 9 69 41 16 97 50 19 24
// 47 46 22 52 80 56 65 89 42 29 94 51 35 1 25 65 88 15 44 57 28 92 60 66 33 37 38 52 76 29 75 8
