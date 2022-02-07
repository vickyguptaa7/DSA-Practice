#include <iostream>
using namespace std;

struct Element
{
    int ele;
    int freq;
};

void N_By_K(int arr[], int n, int k)
{
    if (k < 2)
        return;

    Element Ans[k - 1];
    for (int i = 0; i <= k - 2; i++)
    {
        Ans[i].ele = -1;
        Ans[i].freq = 0;
    }

    for (int i = 0; i < n; i++)
    {
        bool chk = true; // Check If The Any Value Of The Answer Array Updated
        for (int j = 0; j <= k - 2; j++)
        {
            if (Ans[j].ele == arr[i])
            {
                chk = false;
                Ans[j].freq++;
                break;
            }
        }

        if (chk)
        {
            for (int j = 0; j <= k - 2; j++)
            {
                if (Ans[j].freq == 0)
                {
                    chk = false;
                    Ans[j].ele = arr[i];
                    Ans[j].freq =1;
                    break;
                }
            }
        }

        if (chk)
        {
            for (int j = 0; j <= k - 2; j++)
            {
                Ans[j].freq--;
            }
        }
    }
    for (int i = 0; i <= k - 2; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (Ans[i].ele == arr[j])
                count++;
        }
        if (count > n / k)
            cout << Ans[i].ele << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
  
    N_By_K(arr, n, k);

    return 0;
}