#include <iostream>
using namespace std;

struct Data_Type
{
    int data;
    int freq;
};

void More_Than_N_by_K(int *arr, int n, int k) // T.C - O(n^2)
{
    int Count = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / k)
        {
            Count++;
        }
    }
    cout << endl;
}

void Merge(int arr[], int s, int m, int n)
{
    int p = m - s + 1;
    int q = n - m;

    int arr1[p];
    int arr2[q];

    for (int i = 0; i < p; i++)
    {
        arr1[i] = arr[i + s];
    }

    for (int i = 0; i < q; i++)
    {
        arr2[i] = arr[i + m + 1];
    }

    int x = 0, y = 0, z = s;

    while (p > x && q > y)
    {
        if (arr1[x] > arr2[y])
        {
            arr[z] = arr2[y];
            z++;
            y++;
        }
        else
        {
            arr[z] = arr1[x];
            x++;
            z++;
        }
    }
    while (p > x)
    {
        arr[z] = arr1[x];
        x++;
        z++;
    }

    while (q > y)
    {
        arr[z] = arr2[y];
        y++;
        z++;
    }
}

void Merge_Sort(int arr[], int s, int n)
{
    if (n > s)
    {
        int mid = (n + s) / 2;
        Merge_Sort(arr, s, mid);
        Merge_Sort(arr, mid + 1, n);

        Merge(arr, s, mid, n);
    }
}

int More_Than(int *arr, int n, int k)
{
    Merge_Sort(arr, 0, n);

    int count = 1, No = 0;
    bool chk = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            count++;
            chk = false;
        }
        else
        {
            if (count > n / k)
            {
                No++;
            }
            count = 1;
        }
    }
    if (chk == false)
    {
        if (count > n / k)
        {
            No++;
        }
    }
    return No;
}

int More(int arr[], int n, int k)
{
    if (k < 2)
        return 0;
    struct Data_Type temp[k - 1];
    for (int i = 0; i < k - 1; i++)
    {
        temp[i].freq = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < k - 1; j++) // if Eleement Is Present It Increases Freq
        {
            if (arr[i] == temp[j].data)
            {
                temp[j].freq++;
                break;
            }
        }

        if (j == k - 1) // if element Is Not There In The Smaller Array Decrease Freq;
        {
            int l;
            for (int l = 0; l < k - 1; l++)
            {
                if (temp[l].freq == 0)
                {
                    temp[l].data = arr[i];
                    temp[l].freq++;
                    break;
                }
            }

            if (l == k - 1)
            {
                for (l = 0; l < k - 1; l++)
                {
                        temp[l].freq--;
                }
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << More_Than(arr, n, k) << endl;
    return 0;
}