#include <iostream>
using namespace std;

struct MinHeap
{
    int *arr;
    int size;
    int capacity;
    MinHeap(int cap)
    {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Overflow!" << endl;
            return;
        }
        size++;
        arr[size - 1] = val;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i]; i = parent(i))
        {
            swap(arr[i], arr[parent(i)]);
        }
    }
    void MinHeapify(int i)
    {
        int l = left(i), r = right(i), smallest = i;
        if (l < size && arr[i] > arr[l])
            smallest = l;
        if (r < size && arr[smallest] > arr[r])
            smallest = r;
        if (smallest != 0)
        {
            swap(arr[i], arr[smallest]);
            MinHeapify(smallest);
        }
    }
    int extractMin()
    {
        if (size == 0)
        {
            cout << "Underflow" << endl;
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[size];
        }
        size--;
        swap(arr[0], arr[size]);
        MinHeapify(0);
        return arr[size];
    }
    void decrease_key(int i, int val)
    {
        if (i <= size)
        {
            cout << "Index Out Of Bound!" << endl;
            return;
        }
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    void Delete(int i)
    {
        decrease_key(i,INT_MIN);
        extractMin();
    }
    void Build_minHeap()
    {
        for(int i=(size-2)/2;i>=0;i--)
        MinHeapify(i);
    }
};

int main()
{
    return 0;
}