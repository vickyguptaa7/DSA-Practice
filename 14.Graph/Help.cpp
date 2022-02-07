#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    vector<unordered_map<int,int>>list(3);
    list[1][1]+=1;
    cout<<list[1][1]<<endl;
    return 0;
}