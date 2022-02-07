#include<iostream>
#include<algorithm>

using namespace std;

struct Interval
{
    int strt;
    int end;
};

bool myComp(Interval a,Interval b)
{
    return a.strt<b.strt;
}

int Merge_Interval(Interval arr[],int n)
{
    sort(arr,arr+n,myComp);
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[res].end>=arr[i].strt)
        {
            arr[res].strt=min(arr[res].strt,arr[i].strt);
            arr[res].end=max(arr[res].end,arr[i].end);
        }
        else
        {
            res++;
            arr[res]=arr[i];
        }
    }
    return res;
}

int main(){
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
    for (int i = 0; i <=n; i++)
    {
        cout << arr[i].strt << " ";
        cout << arr[i].end << endl;
    }
    return 0;
}