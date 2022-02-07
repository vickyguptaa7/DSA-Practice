#include <iostream>
using namespace std;

void Merge(int arr[], int s, int m, int n)
{
    int p = m - s + 1, q = n - m;
    int *arr_1 = new int[p];
    int *arr_2 = new int[q];

    for (int i = 0; i < p; i++)
    {
        arr_1[i] = arr[i + s];
    }

    for (int i = 0; i < q; i++)
    {
        arr_2[i] = arr[i + m + 1];
    }

    int x = 0, y = 0, z = s;

    while (p > x && q > y)
    {
        if (arr_1[x] > arr_2[y])
        {
            arr[z] = arr_2[y];
            y++;
            z++;
        }
        else
        {
            arr[z] = arr_1[x];
            x++;
            z++;
        }
    }

    while (p > x)
    {
        arr[z] = arr_1[x];
        x++;
        z++;
    }
    while (q > y)
    {
        arr[z] = arr_2[y];
        y++;
        z++;
    }
}
void Merge_Sort(int arr[], int s, int n)
{
    if (n > s)
    {
        int m = (s + n) / 2;
        Merge_Sort(arr, s, m);
        Merge_Sort(arr, m + 1, n);

        Merge(arr, s, m, n);
    }
}

int doUnion(int a[], int n, int b[], int m)
{

    int arr[n + m];
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }

    for (int i = 0; i < m; i++)
    {
        arr[n + i] = b[i];
    }

    Merge_Sort(arr, 0, n + m);

    int count = 1;
    for (int i = 1; i < n + m; i++)
    {
        if (arr[i - 1] != arr[i])
            count++;
    }
    return count;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int *a=new int[n];
    int *b=new int[m];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    cout<<doUnion(a,n,b,m)<<endl;
    return 0;
}