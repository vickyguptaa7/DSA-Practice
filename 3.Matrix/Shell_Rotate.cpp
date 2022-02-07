#include <iostream>
#include <vector>
using namespace std;

void Reverse_Array(vector<int> &arr, int s, int e)
{
    if(s>e)return;
    int j=0;
    for (int i = s; i <= (s + e) / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[e - j];
        arr[e - j++] = temp;
    }
}

void Rotate_Array(vector<int> &arr, int k)
{
    k = k % arr.size();
    Reverse_Array(arr, 0, arr.size() - 1);
    Reverse_Array(arr, 0, k-1);
    Reverse_Array(arr, k , arr.size() - 1);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int rows = 0, rowe = n - 1, cols = 0, cole = m - 1;
    while (rows < rowe || cols < cole)
    {
        vector<int> oned;
        
        if(cols!=cole)
        for (int i = cols; i <= cole; i++)
        {
            oned.push_back(arr[rows][i]);
        }

        if(cols!=cole)
        for (int i = rows + 1; i <= rowe; i++)
        {
            oned.push_back(arr[i][cole]);
        }

        for (int i = cole - 1; i >= cols; i--)
        {
            oned.push_back(arr[rowe][i]);
        }

        for (int i = rowe - 1; i >= rows + 1; i--)
        {
            oned.push_back(arr[i][cols]);
        }

        for (int i = 0; i < oned.size(); i++)
        {
            cout << oned[i] << " ";
        }
        cout << endl;
        Rotate_Array(oned, k);
        for (int i = 0; i < oned.size(); i++)
        {
            cout << oned[i] << " ";
        }
        cout << endl;
        int q = 0;
        for (int i = cols; i <= cole; i++)
        {
            arr[rows][i] = oned[q++];
        }
        rows++;
        for (int i = rows; i <= rowe; i++)
        {
            arr[i][cole] = oned[q++];
        }
        cole--;
        for (int i = cole; i >= cols; i--)
        {
            arr[rowe][i] = oned[q++];
        }
        rowe--;
        for (int i = rowe; i >= rows; i--)
        {
            arr[i][cols] = oned[q++];
        }
        cols++;
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // int n;
    // cin>>n;
    // vector<int>arr;
    // for(int i=0;i<n;i++)
    // {
    //     int num;
    //     cin>>num;
    //     arr.push_back(num);
    // }
    // Rotate_Array(arr,0);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}