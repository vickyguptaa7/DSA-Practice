#include<iostream>
#include<unordered_map>
using namespace std;

class LRUcache{
    public:
    class node{
        public:
        int key;
        int val;
        node*next;
        node*prev;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
            next=nullptr;
            prev=nullptr;
        }
    };
    node*tail=new node(-1,-1);
    node*head=new node(-1,-1);
    int capacity;
    unordered_map<int,node*>umap;
    
    LRUcache(int _capacity)
    {
        capacity=_capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* newnode)
    {
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node*delnode)
    {
        node*delnext=delnode->next;
        node*delprev=delnode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int _key)
    {
        if(umap.find(_key)!=umap.end())
        {
            node*resnode=umap[_key]; // stroing that node
            int res=resnode->val; // storing the value of that node
            umap.erase(_key);  // erasing the data from map 
            deletenode(resnode); //delete this node from the particular postion
            addnode(resnode);   // adding the deleted node first
            umap[_key]=head->next; // storing new address
            return res;     

        }
        else
        return -1;
    }

    void put(int _key,int _val)
    {
        if(umap.find(_key)!=umap.end())
        {
            node*existingnode=umap[_key];
            umap.erase(_key);
            deletenode(existingnode);
        }
        if(umap.size()==capacity)
        {
            umap.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(_key,_val));
        umap[_key]=head->next;
    }
};

int main()
{   
    LRUcache t1(2);
    t1.put(1,4);
    cout<<t1.get(1)<<endl;
    t1.put(2,6);
    cout<<t1.get(2)<<endl;
    t1.put(3,7);
    cout<<t1.get(1)<<endl;
    

    return 0;
}