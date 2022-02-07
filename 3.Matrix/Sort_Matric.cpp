#include <iostream>
using namespace std;

void Merge(int **Matrix, int i, int m, int n, int col)
{
    int p = m - i + 1, q = n - m;
    int arr1[p], arr2[q];

    for (int j = 0; j < p; j++)
    {
        int num=i+j;
        arr1[j] = Matrix[num/ col][num%col];
    }

    for (int j = 0; j < q; j++)
    {
        int num=m+1+j;
        arr2[j] = Matrix[num / col][num%col];
    }

    int x = 0, y = 0, z = i;

    while (p > x && q > y)
    {
        if (arr1[x] > arr2[y])
        {
                Matrix[z / col][z%col] = arr2[y];
            y++;
            z++;
        }
        else
        {
                Matrix[z / col][z%col] = arr1[x];
            x++;
            z++;
        }
    }

    while (p > x)
    {
            Matrix[z / col][z%col] = arr1[x];
        x++;
        z++;
    }

    while (q > y)
    {
        Matrix[z / col][z%col] = arr2[y];
        y++;
        z++;
    }
}

void Merge_Sort(int **Matrix, int i, int n, int col)
{
    if (i < n)
    {
        int m = (i + n) / 2;
        Merge_Sort(Matrix, i, m, col);
        Merge_Sort(Matrix, m + 1, n, col);

        Merge(Matrix, i, m, n, col);
    }
}

void Sort_Matrix(int **Matrix, int n, int m)
{
    int total = (n * m)-1;
    Merge_Sort(Matrix, 0, total, m);
}

void Sort_Naive(int **arr,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int p=i;p<n;p++)
            {
                for(int q=j;q<m;q++)
                {
                    if(arr[i][j]>arr[p][q])
                    {
                        int temp=arr[i][j];
                        arr[i][j]=arr[p][q];
                        arr[p][q]=temp;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    Sort_Matrix(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}