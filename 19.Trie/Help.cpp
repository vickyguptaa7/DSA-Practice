#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s = "ab";
    vector<string> arr = {"aa"};
    cout << s.compare(arr[0]) << "\n";
    return 0;
}