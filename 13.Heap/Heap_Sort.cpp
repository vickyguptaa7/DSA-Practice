#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[i] < arr[left])
        smallest = left;
    if (right < n && arr[smallest] < arr[right])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        i = smallest;
        heapify(arr, n, i);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[0], arr[n - 1 - i]);
        heapify(arr, n - 1 - i, 0);
    }
}

int main()
{
    int arr[]={5,8,4,3,2,1};
    heapSort(arr,6);
    for(int i=0;i<6;i++)cout<<arr[i]<<endl;
    return 0;
}