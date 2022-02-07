#include<iostream>
using namespace std;

struct dll
{
    int data;
    dll *prev;
    dll *next;
    dll(int val)
    {
        prev=nullptr;
        next=nullptr;
        data=val;
    }
};
dll *top=nullptr;




int main(){
    return 0;
}