#include <iostream>
using namespace std;

struct myhash
{
    int bucket;
    int *table;
    int size;
    myhash(int n)
    {
        bucket = n;
        size = 0;
        table = new int[bucket];
        for (int i = 0; i < bucket; i++)
            table[i] = -1; // -1 indicates empty where as 0 indicates deleted
    }
    int hash(int key)
    {
        return key % bucket;
    }
    bool isempty()
    {
        return size == bucket;
    }
    bool insert(int key)
    {
        if(isempty())return false;
        int hashcode = hash(key);

        while(table[hashcode]!=key&&table[hashcode]!=-1&&table[hashcode]!=0)
        {
            hashcode = (hashcode + 1) % bucket;
        }
        if(table[hashcode]==key)
        {
            return false;
        }
        else
        {
            table[hashcode] = key;
            size++;
            return true;
        }
    }
    bool remove(int key)
    {
        int hashcode = hash(key);
        int hvalue=hashcode;
        while(table[hashcode]!=-1)
        {
            if(table[hashcode]==key)
            {
                table[hashcode]=0;
                size--;
                return 1;
            }
            hashcode=(hashcode+1)%bucket;
            if(hashcode==hvalue)
            return false;
        }
        return false;
    }
    bool search(int key)
    {
        int hashcode = hash(key);
        int hvalue = hashcode;
        while (table[hashcode] != -1)
        {
            if (table[hashcode] == key)
                return true;
            hashcode = (hashcode + 1) % bucket;
            if (hashcode == hvalue)
                return false;
        }
        return false;
    }
};

int main()
{
    int n[] = {19, 20, 39, 47, 5, 66, 57, 81, 29, 10, 11};
    myhash *map = new myhash(11);
    for (int i = 0; i < 11; i++)
    {
        map->insert(n[i]);
    }
    cout << map->search(49) << endl;
    cout<<map->remove(49)<<endl;
    cout << map->search(29) << endl;
    return 0;
}