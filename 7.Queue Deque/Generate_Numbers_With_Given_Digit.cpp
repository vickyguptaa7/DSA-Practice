#include <iostream>
#include <queue>
using namespace std;

void Generate_Numbers(string str, int n)
{
    int len = str.length();
    queue<string> q;
    for (int i = 0; i < len; i++)
    {
        q.push(str.substr(i,1));
    }

    for (int j = 0; j < n; j++)
    {
        string s = q.front();
        q.pop();
        cout<<s<<" ";
        for (int i = 0; i < len; i++)
        {
            q.push(s+str.substr(i,1));
            
        }
    }
    cout<<endl;
}

int main()
{
    cout << "Digits : ";
    string str;
    cin >> str;
    int n;
    cout << "No Of Times It Should Be Printed : ";
    cin >> n;
    Generate_Numbers(str, n);
    return 0;
}