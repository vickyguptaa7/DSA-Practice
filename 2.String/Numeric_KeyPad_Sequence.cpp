#include<iostream>
using namespace std;

string keypad[]={" ","2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};


int main(){
    string str;
    getline(cin,str);
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(str[i]==' ')
        {
            cout<<0;
        }
        else{
        int num=str[i]-'A'+1;
        cout<<keypad[num];
        }
    }

    return 0;
}