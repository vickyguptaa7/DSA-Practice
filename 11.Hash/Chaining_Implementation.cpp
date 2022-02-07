#include<iostream>
#include<iostream>
#include<list>

using namespace std;

struct myhash
{
    int bucket;
    list<int>*table;
    myhash(int b)
    {
        bucket=b;
        table=new list<int>[bucket];
    }
    int hash(int key)
    {
        return key%bucket;
    }
    void insert(int key)
    {
        int hashcode=hash(key);
        table[hashcode].push_back(key);
    }
    void remove(int key)
    {
        int hashcode=hash(key);
        if(search(key))
        table[hashcode].remove(key);
        else
        cout<<"The Key Is Not Present\n";
    }
    bool search(int key)
    {
        int hashcode=hash(key);
        for(auto x:table[hashcode])
        {
            if(key==x)
            return true;
        }
        return false;
    }
};

int main(){
    int n[]={19,20,39,47,5,66,57,81,29,10,11};
    myhash *map=new myhash(11);
    for(int i=0;i<11;i++)
    {
        map->insert(n[i]);
    }
    cout<<map->search(49)<<endl;
    map->remove(49);
    cout<<map->search(29)<<endl;
    return 0;
}