#include <iostream>
using namespace std;

int Computer_Not_Get(string str, int k)
{
    int n = str.length();
    int farr[256] = {0};
    int count = 0, customer = 0;
    for (int i = 0; i < n; i++)
    {
        if (farr[str[i]] != 1)
        {
            if (customer >= k)
                count++;
            customer++;
            farr[str[i]] = 1;
        }
        else
        {
            customer--;
            farr[str[i]] = 0;
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string str;
        cin >> str;
        int k;
        cin >> k;
        cout << Computer_Not_Get(str, k) << endl;
    }

    return 0;
}
/*
5 
ABBAJJKZKZ 2 
GACCBDDBAGEE 3 
GACCBGDDBAEE 3 
ABCBCA 1 
ABCBCADEED 1
*/