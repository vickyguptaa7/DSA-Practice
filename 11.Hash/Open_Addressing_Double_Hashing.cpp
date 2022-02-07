#include<iostream>
using namespace std;

struct mydhash
{
    int bucket;
    int*table;
    int rprime;
    int size;
    mydhash(int n)
    {
        bucket=n;
        size=0;
        table=new int[bucket];
        if(bucket>1)
        rprime=bucket-1;
        else rprime=1;

        for(int i=0;i<bucket;i++)table[i]=-1;// -1 for empty and -2 for delete
    }
    int hash1(int key)
    {
        return key%bucket;
    }
    int hash2(int key)
    {
        return (rprime-(key%rprime));
    }
    bool isempty()
    {
        return (size==bucket);
    }
    bool insert(int key)
    {
        if(isempty())return false;
        
        int hashcode1=hash1(key);
        int hashcode2=hash2(key);
        
        while(table[hashcode1]!=key&&table[hashcode1]!=-1&&table[hashcode1]!=-2)
        {
            hashcode1=(hashcode2+hashcode1)%bucket;
        }
        
        if(table[hashcode1]==key)return false;
        
        table[hashcode1]=key;
        
        size++;

        return true;
    }
    bool remove(int key)
    {
        int hashcode1=hash1(key);
        int hashcode2=hash2(key);

        int hvalue=hashcode1;

        while(table[hashcode1]!=-1)
        {
            if(table[hashcode1]==key) // -2 for deleting
            {
                table[hashcode1]=-2;
                size--;
                return true;
            }
            hashcode1=(hashcode1+hashcode2)%bucket;
            if(hashcode1==hvalue)
            return false;
        }
        return false;
    }
    bool search(int key)
    {
        int hashcode1=hash1(key);
        int hashcode2=hash2(key);

        int hvalue=hashcode1;

        while(table[hashcode1]!=-1)
        {
            if(table[hashcode1]==key)// -1 for empty
            {
                return true;
            }
            hashcode1=(hashcode1+hashcode2)%bucket;
            if(hashcode1==hvalue)
            {
                return false;
            }
        }
        return false;
    }
    void showTable()
    {
        for(int i=0;i<bucket;i++)cout<<table[i]<<endl;
    }
};


int main(){
    int n[] = {49,63,56,52,54,48};
    mydhash *map = new mydhash(7);
    for (int i = 0; i < 11; i++)
    {
        map->insert(n[i]);
    }
    
    cout << map->search(49) << endl;
    cout<<map->remove(49)<<endl;
    cout << map->search(29) << endl;

    map->showTable();
    return 0;
}