#include <iostream>
using namespace std;

struct Interval
{
    int strt;
    int end;
};

int Merge_Interval(Interval arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            bool chk;
            int Max;
            if(arr[i].strt>arr[j].strt)
            {
                Max=arr[i].strt;
                chk=false;
            }
            else
            {
                Max=arr[j].strt;
                chk=true;
            }
            if((chk==true&&arr[i].strt<=Max&&arr[i].end>=Max)
            ||(chk==false&&arr[j].strt<=Max&&arr[j].end>=Max))
            {
                arr[i].strt = min(arr[i].strt, arr[j].strt);
                arr[i].end = max(arr[i].end, arr[j].end);
                if (i != j)
                {
                    if(i<j)
                    for (int k = j + 1; k < n; k++)
                    {
                        arr[k - 1].strt = arr[k].strt;
                        arr[k - 1].end = arr[k].end;
                    }
                    
                    if(j<i)
                    for(int k=i+1;k<n;k++)
                    {
                        arr[k - 1].strt = arr[k].strt;
                        arr[k - 1].end = arr[k].end;
                    }
                    n--;
                }
            }
        }
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    Interval arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].strt;
        cin >> arr[i].end;
    }

    n = Merge_Interval(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].strt << " ";
        cout << arr[i].end << endl;
    }

    return 0;
}