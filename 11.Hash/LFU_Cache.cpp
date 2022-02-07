#include <iostream>
#include <unordered_map>
using namespace std;

struct node
{
    int key;
    int val;
    int count;
    node *next;
    node *prev;
    node(int _key, int _val)
    {
        key = _key;
        val = _val;
        count = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct list
{
    int size;
    node *head;
    node *tail;
    list()
    {
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void deletenode(node *delnode)
    {
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
    void addnode(node *newnode)
    {
        node *nextnode = head->next;
        newnode->next = nextnode;
        newnode->prev = head;
        head->next = newnode;
        nextnode->prev = newnode;
        size++;
    }
};

class LFUcache
{
    unordered_map<int,list>freqListMap;
    unordered_map<int, node *> keyNode;
    int maxsizeCache;
    int minFreq;
    int cursize;
    public:
    LFUcache(int _capacity)
    {
        maxsizeCache=_capacity;
        minFreq=0;
        cursize=0;
    }
    void UpdateFreqListMap(char *node)
    {
        keyNode.erase(node->key);
    }
};

int main()
{

    return 0;
}