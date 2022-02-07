#include <iostream>
#include <unordered_map>
using namespace std;

void Distinct_Every_Window_B(int arr[], int n, int k)
{
    if (k > n)
    {
        cout << "Invalid N Must Be Greater Than K" << endl;
        return;
    }

    for(int i=0;i<=n-k;i++)
    {
        int Duplicate=0;
        for(int j=i;j<i+k;j++)
        {
            for(int p=j+1;p<i+k;p++)
            {
                if(arr[j]==arr[p])
                {
                    Duplicate++;
                }
            }
        }
        cout<<k-Duplicate<<" ";
    }
    cout<<endl;
}

void Distinct_Every_Window_O(int arr[], int n, int k)
{
    if (k > n)
    {
        cout << "Invalid N Must Be Greater Than K" << endl;
        return;
    }

    unordered_map<int, int> umap;
    for (int i = 0; i < k; i++)
    {
        umap[arr[i]]++;
    }
    cout << umap.size() << " ";
    for (int i = k; i < n; i++)
    {
        if (umap[arr[i - k]] > 1)
        {
            umap[arr[i - k]]--;
        }
        else
        {
            umap.erase(arr[i - k]);
        }
        umap[arr[i]]++;
        cout << umap.size() << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Distinct_Every_Window_B(arr, n, k);
    return 0;
}